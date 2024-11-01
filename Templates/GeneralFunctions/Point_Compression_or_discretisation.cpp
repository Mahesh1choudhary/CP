#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


// 1-D point compression
/*
we have two methods ->
 1- sort all points, remove duplicates, then index of point will be its new value
 2- use map
*/

// Method 1
int a[n],b[m]
int vec[n+m]    // define its size to be greater than maximum possible distinct elements

int u=0;
for(int i=0;i<n;i++) vec[u]=a[i],u++;
for(int i=0;i<m;i++) vec[u]=b[i], u++;

sort(vec,vec+u);

for(int i=0;i<n;i++) a[i]=lower_bound(vec,vec+u)-vec;
for(int i=0;i<m;i++) b[i]=lower_bound(vec,vec+u)-vec;

// Method 1.1
// first insert all elements into vec
sort(vec.begin(),vec.end());
vec.resize(unique(vec.begin(),vec.end())-vec.begin());
for(int i=0;i<n;i++){
    a[i]=lower_bound(vec.begin(),vec.end(),b[i])-vec.begin();
    b[i]=lower_bound(vec.begin(),vec.end(),b[i])-vec.begin();
}




// Method 2 - In this method, we will use map
sort(a.begin(), a.end());
map<int,int> mp;
int curr=0;
for(int i=0;i<n;i++){
    if(mp.count(a[i])==0){
        mp[a[i]]=curr;
        curr++;
    }
    a[i]=mp[a[i]];
}










