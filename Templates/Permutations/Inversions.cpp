#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// counting number of inversions in array a- (for both distinct and duplicates)
vector<int> a;
vector<int> dummy;
// method 1 -> using divide and conquer +merge sort
// O(nlogn) time complexity ,  O(n) extra space
LL merge(int strt, int ed){
    int mid=strt+(ed-strt)/2;
    int i=strt, j=mid+1;
    LL cnt=0;
    for(int k=strt;k<=ed;k++){
        if(i>mid){
            dummy[k]=a[j];
            j++;
        }
        else if(j>ed){
            dummy[k]=a[i];
            i++;
        }
        else{
            if(a[i]>a[j]){
                cnt+=(mid-i+1);
                dummy[k]=a[j];
                j++;
            }
            else{
                dummy[k]=a[i];
                i++;
            }
        }
    }
    for(int i=strt;i<=ed;i++) a[i]=dummy[i];
    return cnt;
}



long long inversions(int strt, int ed){
    // if single element then 0 zero inversions
    if(strt==ed){
        return 0;
    }

    LL cnt=0;
    int mid=strt+(ed-strt)/2;
    // finding inversions in strt to mid, and then mid+1 to ed
    cnt+=inversions(strt,mid)+inversions(mid+1,ed);

    // combining inversions of two halfs
    cnt+=merge(strt,ed);
    return cnt;

}





// Method 2 -> We can use segment tree where we store all element in range l to r in sorted order at each node, now to find all elements that are greater than a[i] from 0 to i-1, just do 
// search with binaray search which overall gives O(n*(logn)^2)


// method 3 -> using some point update range sum data structure like fenwick tree or segment tree

// Process the array from left to right. Now when you are at the index i, you want to count all the elements smaller that A[i], 
// which is to the left of i. For this make a query(0, A[i] - 1) in the segment tree. This is true because the segment tree is
// going to store the frequency of the occurrence. So after the query, do an update(A[i], 1), which adds a +1 to the index A[i] 
// in the segment tree.
// This is generally true if a[i]<1e6, but if a[i]<1e9 or something but n=1e6, then just map values of a[i] to a permutation of length n 
// Link -> https://discuss.codechef.com/t/how-to-count-number-of-inversion-in-an-array-using-segment-tree/73312/6

// maping
vector<int> maping(a.begin(),a.end());
sort(maping.begin(), maping.end());
// removing duplicates
maping.resize(unique(maping.begin(),maping.end())-maping.begin());
for(int i=0;i<n;i++){
    a[i]=lower_bound(maping.begin(),maping.end(),a[i])-maping.begin()+1;
}
// we can also done maping using map, if we don't want to change values of array a

// incomplete

































// GOOD QUESTIONS
// 1 - https://codeforces.com/contest/1917/problem/D

