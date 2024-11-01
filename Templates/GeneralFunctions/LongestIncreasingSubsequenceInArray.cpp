#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// Finding LIS can be applied to finding LIS in pairs too -> eg - https://codeforces.com/problemset/problem/1575/L

// Finding Longest increasing subsequence in an array
// longest non decreasing can also be found with change in equality sign and binary search
// we can also find longest decreasing subsequence with the same concept
// LINK -  https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#solution-in-on-log-n-with-dynamic-programming-and-binary-search

// Basic Algorithm -> d[l]= a[i] if there is longest increasing sequence of length l that ends in a[i] and there is no longest increasing sequence of length l that ends in a smaller number.
// d will always be in sorted order, d is initialized as d[0]=-INF, d[i]=INF i>0 , so we can find l by binary search for a given i


// O(nlogn) time complexity , O(n) space complexity

vector<int> a;
int LIS(){
    int n=a.size();
    const int INF=1e9;  // some value that is greater than every element of a
    vector<int> d(n+1,INF);
    d[0]=-INF;

    for(int i=0;i<n;i++){
        int l=upper_bound(d.begin(),d.end(),a[i])- d.begin();
        if(d[l-1]<a[i] && a[i]<d[l]){
            d[l]=a[i];
        }
        /* For longest non decreasing sequence 
        if(d[l-1]<=a[i] && a[i]<d[l]){d[l]=a[i]};
        
        => for decreasing sequence => one of the solution is to reverse a and find longest increasing sequence
        */
    }

    int ans=0;
    for(int l=0;l<=n;l++){
        if(d[l]<INF){
            ans=l;
        }
    }
    return ans;

}


void Restore_LIS(){
    // For restoring, we need to maintain array of index of elements in d array, and array of ancestors- p[i] -index of previous element for the optimal subsequence ending in element i
    int n=a.size();
    vector<int> index(n+1,-1); // index[l]=k -> index of element placed at d[l]
    vector<int> p(n+1,-1);   // p[i] - index of parent/ previous element of a[i] in optimal subsequence
    
    const int INF=1e9;
    vector<int> d(n+1,1e9);
    d[0]=-1e9;

    for(int i=0;i<n;i++){
        int l=upper_bound(d.begin(),d.end(), a[i])-d.begin();
        if(d[l-1]<a[i] && a[i]<d[l]){
            d[l]=a[i];
            index[l]=i;
            parent[i]=index[l-1];
        }

    } 

    int ans=0;
    for(int l=0;l<=n;l++){
        if(d[l]<INF){
            ans=l;
        }
    }

    // Restoring the subsequence
    int x=index[ans];
    vector<int> sequence;
    while(x!=-1){
        sequence.pb(a[x-1]);
        x=parent[x];
    }

    reverse(sequence.begin(), sequence.end());
    for(int i=0;i<ans;i++){
        cout<<sequence[i]<<" ";
    }
    cout<<endl;

}




// We can also use data-structure approach as given in link


// To find number of longest increasing subsequences, we need to use segment tree approach, binary search approach cannot be used here


























//  LIS ON PAIR OF INTS
// LINK -> https://codeforces.com/blog/entry/43319
// LINK -> https://codeforces.com/problemset/problem/1575/L
// LINK -> https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/
// LINK -> https://stackoverflow.com/questions/8716934/longest-increasing-subsequence-lis-with-two-numbers








/*
Very good questions
Q1 - https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/solutions/999153/java-c-python-lcs-to-lis/

*/

