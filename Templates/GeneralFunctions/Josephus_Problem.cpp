#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// J(n,k) = ((J(n-1,k) + k-1)mod n) + 1=> if lowest number starts from 1
// OR J(n,k) = (J(n-1,k) + k)mod n => for 0 indexing
// O(n) approach -> used generally when k>n
// below code is 0-indexed
int josephus(int n, int k){
    int res=0;
    for(int i=1;i<=n;i++){
        res=(res+k)%n;
    }
    return res+1;
}

// O(klogn) approach -> used when k<n

// below is for 0-indexing -> to find 1-index answer, add one in the final answer
int josephus(int n, int k){
    if(n==1) return 0;
    if(k==1) return n-1;
    if(k>n){
        return (josephus(n-1,k)+k)%n;
    }
    int cnt=n/k;
    int res= josephus(n-cnt,k);
    res-=n%k;
    if(res<0) res+=n;
    else{
        res+=res/(k-1);
    }
    return res;
}
