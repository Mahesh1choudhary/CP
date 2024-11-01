#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// LINK -> https://cp-algorithms.com/data_structures/sparse-table.html

// For immutable array- values of array remains same between two queries
// RANGE QUERIES in O(logn), and range min/max queries in O(1);
// main idea- precompute all answers for range queries with power of two length. Then different range queries can be answered by splitting the range into ranges with powers of two and combining them to compute answer.

// will use 2-D array for storing the answers. st[i][j] will store answer for range [j,j+2^i -1] of length 2^i
// size of 2-D array will be (k+1)*MAXN, where MAXN- biggest possible array length. K>= floor(log2(MAXN)), as 2^[log2(MAXN)] is the 
// biggest power of two that we support.

// choose k as maximum possible power of 2 such that 2^k<=MAXN, where MAXN- maximum possible query value
// generally for MAXN<=1e7, k=25 is good value; MAXN imension is second to allow (cache friendly) consecutive memory accesses.
int st[k+1][MAXN];
for(int i=1;i<=k;i++){
    for(int j=0;j+(1<<i)<=N;j++){
        st[i][j]=f(st[i-1][j], st[i-1][j+(1<<(i-1))]);
    }
}
// here function f depends on type of query- range sum, range min,etc;
// for range sum- it will compute the sum, for range min queries it will compute minimm, etc.
// TIME COMPLEXITY OF PRECOMPUTATION- O(NlogN), as k is almost equal to logN


// to answer query for the range [L,R], we iterate over all powers of two starting from the biggest one. As soon as power of two(2^i) is smaller or equal to the length of the range
// (=R-L+1), we process the first part of range [L,L+2^i -1], and compute with the remaining range [L+2^i, R];
long long ans=0;
for(int i=k;i>=0;i--){
    if((1<<i)<=R-L+1){
        //update or change ans
        L+=(1<<i);// update range
    }
}
// TIME COMPLEXITY OF QUERY - O(logMAXN);


// For range min/max or other IDEMPOTANCE operations, we can do query in O(1); function/operator f is idempotent if f(f)=f;
// here we will split the range into two overlapping ranges instead of multiple range
// then Query([L,R])=min(st[i][L],st[i][R-2^i +1]), where i=log2(R-L+1)
// for this we will precompute all logarithms;
int lg[MAXN+1];
lg[1]=0;
for(int i=2;i<=MAXN;i++){
    lg[i]=lg[i/2] +1;
}
// or for better efficiency, log can be computed by width of number binary-1, in constant space and time.




// DISJOINT SPARSE TABLE -> https://discuss.codechef.com/t/tutorial-disjoint-sparse-table/17404











// MIN sparse table


for(int i=n-1;i>=0;i--){
    minel[i][0]=a[i];
    for(int j=1;i+(1<<j)<=n;j++){
        minel[i][j]=min(minel[i][j-1], minel[i+(1<<(j-1))][j-1]);
    }
}

int find_min(int l, int r){
    int x=log2(r-l+1);
    return min(minel[l][x], minel[r-(1<<x)+1][x]);
}










/*

Q1 - https://codeforces.com/problemset/problem/893/F    -> new idea related to sparse table


*/
