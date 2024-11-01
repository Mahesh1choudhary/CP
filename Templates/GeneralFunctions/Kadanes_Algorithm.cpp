#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// LINK -> https://cp-algorithms.com/others/maximum_average_segment.html

// subarray with maximal sum

// ALGORITHM 1 -> let s be prefix sum array (no need to create), for given r let maximal sum be s[r]-s[l-1], so need to maintain l with minimum s[l-1];
// We can do this for each r and take maximum of all, and subarray with maximum sum will be l to r (both inclusive)

// O(n)
vector<int> a;
int ans=a[0], ans_l=0, ans_r=0;
int sum=0; // prefix sum
int min_sum=0; // minimum value of prefix sums among all values
int min_pos=-1; // index where minimum prefix sum occurs

for(int r=0;r<n;r++){
    sum+=a[r];
    int cur=sum-min_sum;
    if(cur>ans){
        ans=cur;
        ans_r=r;
        ans_l=min_pos+1;
    }
    if(sum<min_sum){
        min_sum=sum;
        min_pos=r;
    }
}




// ALGORITHM 2 -> Kadane's algorithm
// go through array and accumulate the current partial sum in some variable s, if at some point s is negative, just assign s=0.
// As maximum of all the values that the variable s is assigned to during the algorithm will be answer to the problem

// O(n)

int ans=a[0], ans_l=0, ans_r=0;
int sum=0; // prefix sum
int min_pos=-1; // index where sum<0

for(int r=0;r<n;r++){
    sum+=a[r];
    if(sum>ans){
        ans=sum;
        ans_r=r;
        ans_l=min_pos+1;
    }
    if(sum<0){
        sum=0;
        min_pos=r;
    }
}
























// To find subarray with minimal sum, just reverse the sign of all elements and find subarray with maximum sum



















