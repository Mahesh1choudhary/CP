#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Link -> https://cp-algorithms.com/algebra/factorial-modulo.html

// To compute some number modulo p, where both numberator and denominator contains factorials
// And p is relatively smaller

/*
NORMAL CASE ->  compute factorials of all possible numbers mode p, and use inverse to get the answer
*/

// If we precompute factorial of 1  to p-1 mod p, then O(p+logn)(base of log is p), otherwise plogn ( base is p)

int factmod(int n, int p){
    vector<int> fac(p);
    fact[0]=1;
    for(int i=1;i<p;i++) fact[i]=(fact[i-1]*i)%p;

    int ans=1;
    while(n>1){
        if((n/p)%2){
            ans=(-ans+p)%p;
        }
        ans=ans*fact[n%p]%p;
        n/=p;
    }
    return ans;
}


// Multiplicity of p in n!
// using legendre's formula in O(logn)(base p)

int multiplicity(int n, int p){
    int ans=0;
    while(n>0){
        n/=p;
        ans+=n;
    }
}



