					B2. Books Exchange (hard version)
					time limit per test1 second
					memory limit per test256 megabytes
						inputstandard input
						outputstandard output

The only difference between easy and hard versions is constraints.
There are n kids, each of them is reading a unique book. At the end of any day, the i-th kid will give 
his book to the pi-th kid (in case of i=pi the kid will give his book to himself). It is guaranteed that all values 
of pi are distinct integers from 1 to n (i.e. p is a permutation). The sequence p doesn't change from day to day, it is fixed.

For example, if n=6 and p=[4,6,1,3,5,2] then at the end of the first day the book of the 1-st kid will belong to the
4-th kid, the 2-nd kid will belong to the 6-th kid and so on. At the end of the second day the book of the 1-st kid 
will belong to the 3-th kid, the 2-nd kid will belong to the 2-th kid and so on.

Your task is to determine the number of the day the book of the i-th child is returned back to him for the first 
time for every i from 1 to n.

Consider the following example: p=[5,1,2,4,3]. The book of the 1-st kid will be passed to the following kids:

after the 1-st day it will belong to the 5-th kid,
after the 2-nd day it will belong to the 3-rd kid,
after the 3-rd day it will belong to the 2-nd kid,
after the 4-th day it will belong to the 1-st kid.
So after the fourth day, the book of the first kid will return to its owner. The book of the fourth kid will return
to him for the first time after exactly one day.
You have to answer q independent queries.

Input
The first line of the input contains one integer q (1≤q≤1000) — the number of queries. Then q queries follow.
The first line of the query contains one integer n (1≤n≤2⋅105) — the number of kids in the query. 
The second line of the query contains n integers p1,p2,…,pn (1≤pi≤n, all pi are distinct, i.e. p is a permutation), 
where pi is the kid which will get the book of the i-th kid.

It is guaranteed that ∑n≤2⋅105 (sum of n over all queries does not exceed 2⋅105).

Output
For each query, print the answer on it: n integers a1,a2,…,an, where ai is the number of the day the 
book of the i-th child is returned back to him for the first time in this query.

Example
inputCopy
6
5
1 2 3 4 5
3
2 3 1
6
4 6 2 1 5 3
1
1
4
3 4 1 2
5
5 1 2 4 3
outputCopy
1 1 1 1 1 
3 3 3 
2 3 3 2 1 3 
1 
2 2 2 2 
4 4 4 1 4 

Hint : basic dsu









Solution: 

#include <iostream>
#include <vector>
using namespace std;
int n,q,k,i;
int main() {
  cin.tie(0);ios_base::sync_with_stdio(0);
  
  cin >> q ; 
  while(q--)
  	{
  	  	cin>>n ;
		vector<int>A(n),B(n,1);
    	for(int &e : A )
		{
			cin >> e ;
			e--;
		}
    	for( i = 0 ; i < n ; i++)
		{
      		if(B[i]==1)
		  	{
        	for(k = A[i] ; k != i ; k = A[k])
				B[i]++;
        	for(k = A[i] ; k != i ; k = A[k])//union theory in dsu . setting the repetetive path length
				B[k]=B[i];
      		}
    	}
    for(auto e:B)cout<<e<<' ';
	cout<<'\n';
  }
}
