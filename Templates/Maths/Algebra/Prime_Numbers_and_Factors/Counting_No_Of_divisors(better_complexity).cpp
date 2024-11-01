#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// LINK -> https://codeforces.com/blog/entry/22317
// counting no of divisors of a number in O(N^(1/3))

/*
BASIC ALGORITHM -> let n=p*q*r where p<=q<=r, then maximum value of p = n^(1/3)
find all prime divisors <=n^(1/3) and reduce the number n after removing these primes, let it by Y, Now Y<=n^(2/3)
now only three cases are possible:
 1. Y is a prime -> check using miller rabin or pollard rho primality check,  then no of divisors = 2
 2. Y is square of a prime number -> check if Y is perfect square and its square root is prime , then no of divisors = 3  
 3. Y is product of two distinct prime numbers -> if above two cases doesn't happen, then this is the case , then no of divisors = 4
*/

// O(n^(1/3))
long long cnt_divisors(long long n){
    long long ans=1;

    // removing primes below n^(1/3)
    // O(N^(1/3))   -> We assume that N is the original N, and n is updated value after removing factors
    for(long long i=2;i*i*i<=n;i++){
        int cnt=1;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        ans*=cnt;
    }


    if(MillerRabin((u64) n)){
        ans*=2;
        return ans;
    }
    
    long long val=sqrt(n);  // at worst O(N^(1/3)), if sqrt(x) is O(root(x)) ( assuming, don't know real complexity of sqrt)
    // need not check if val is prime, as if n is perfect square, then val has to pe prime
    if(val*val==n){
        ans*=3;
        return;
    }
    if(n!=1){
        ans*=4;
    }
    return ans;
}

// we can try this technique in problems resulting O(root(N)) factorisations









