#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// LINK - https://cp-algorithms.com/data_structures/segment_tree.html#memory-efficient-implementation

// standard segment tree requires 4*n vertices for working on an array of size n. So when n is not a poer of 2, many vertices will remain unused

// Code Idea - https://codeforces.com/blog/entry/65278

// part 1 -> max segment tree ( storing maximum element)

int maxv;
int segtr[2*maxv-1];
int a[maxv];

void build(int v, int tl, int tr){
    if(tl==tr){
        segtr[v]=a[tl];
        return;
    }
    int mid=(tl+tr)/2;
    int v_right=v+(mid-tl+1)*2;
    build(v+1,tl,mid), build(v_right,mid+1,tr);
    segtr[v]=max(segtr[v+1],segtr[v_right]);
}

void update(int v, int tl, int tr, int ind, int val){
    if(tl==tr){
        a[ind]=val;
        segtr[v]=a[ind];
        return;
    }
    int mid=(tl+tr)/2;
    int v_right=v+(mid-tl+1)*2;
    if(ind<=mid) update(v+1,tl,mid,ind,val);
    else update(v_right,mid+1,tr,ind,val);
    segtr[v]=max(segtr[v+1],segtr[v_right]);
}

int query(int v, int tl, int tr, int l, int r){
    if(l>r) return -INF;
    if(l==tl &&  r==tr){
        return segtr[v];
    }
    int mid=(tl+tr)/2;
    int v_right=v+(mid-tl+1)*2;
    return max(query(v+1,tl,mid,l,min(mid,r)), query(v_right,mid+1,tr,max(l,mid+1),r));
}




// PART 2 - keep all elements at each index

vector<long long> segtr[2*maxv-1];
long long a[maxv];

void merge(int v, int left, int right){
    int n=(int)segtr[left].size(), m=(int)segtr[right].size();
    int i=0, j=0;
    for(int k=0;k<n+m;k++){
        if(i==n){
            segtr[v].eb(segtr[right][j]);
            j++;
        }
        else if(j==m){
            segtr[v].eb(segtr[left][i]);
            i++;
        }
        else if(segtr[left][i]<segtr[right][j]){
            segtr[v].eb(segtr[left][i]);
            i++;
        }
        else{
            segtr[v].eb(segtr[right][j]);
            j++;
        }
    }
}

void build(int v, int tl, int tr){
    if(tl==tr){
        segtr[v].eb(a[tl]);
        return;
    }
    int mid=(tl+tr)/2;
    int v_right=v+(mid-tl+1)*2;
    build(v+1,tl,mid), build(v_right,mid+1,tr);
    merge(v,v+1,v_right);
}













