#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;


// LINK => https://cp-algorithms.com/algebra/phi-function.html

// O(sqrt(n))
int phi(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            ans-=ans/i;
        }
    }
    if(n>1){
        ans-=ans/n;
    }
    return ans;

}




// FINDING TOTIENT FUNCTION FROM 1 TO N IN O(nloglogn) using seive

void phi1_to_n(int n){
    vector<int> phi(n+1);
    for(int i=0;i<=n;i++) phi[i]=i;
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            for(int j=i;j<=n;j++){
                phi[j]-=phi[j]/i;
            }
        }
    }
}




// IN Linear time - O(n) using linear seive - https://codeforces.com/blog/entry/54090
vector<bool> is_prime(n+1,true);
vectorInt> phi(n+1),primes;
is_prime[0]=is_prime[1]=false;
phi[1]=1;
for(int i=2;i<=n;i++){
    if(is_prime[i]){
        primes.push_back(i);
        phi[i]=i-1;
    }
    for(int j=0;j<(int)primes.size() && i*prime[j]<=n;j++){
        is_prime[i*prime[j]]=false;
        if(i%prime[j]==0){
            phi[i*prime[j]]=phi[i]*prime[j];
            break;
        }
        else{
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }

}


// Very good questions
// https://codeforces.com/problemset/problem/776/E
/*
suppose we have to compute phi(phi(...n))..)) k times ( k of order 1e12). phi- euler totient function.
 The idea is if n is even then phi(n)<=n/2 as all odd will be coprime to n. so we will compute phi atmost of order logn times
 https://codeforces.com/problemset/problem/776/E

*/
