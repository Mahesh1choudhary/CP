#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using u64 = uint64_t;
using u128 = __uint128_t;

using namespace std;


// LINK -> https://cp-algorithms.com/algebra/primality_tests.html


// METHOD -1 -> TRIAL DIVISION
// check all numbers from 2 to root(n), if no number divided n then it is prime

// O(sqrt(n))
bool isPrime(int n){
    for(int d=2;d*d<=x;d++){
        if(n%d==0){
            return false;
        }
    }
    return x>=2;
}




// METHOD - 2 => MILLER- RABIN PRIMALITY TEST
// let n-1= power(2,s)*d;
// then for some base 'a', check if a^d=1 (mod n) or a^(power(2,r)*d)=-1 (mod n) holds for some 0<=r<=s-1

//If we found a base 'a' which doesn't satisfy any of the above equalities, than we found a witness for the compositeness of n.

// we only need to check all bases a such that a<= 2*((ln(n))^2)

// Generally for 32 bit integers, we need to check only for first 4 prime =(2,3,5,7)
// and for 64 bit integer, it is enough to check for first 12 primes = (2,3,5,7,11,13,17,19,23,29,31,37)

// Implementation for numbers upto 64 bits
// O(logb)
// If __int128 is not supported by compiler, use binary exponentiation or montgomery multiplcation to multiply two large numbers under modulo
long long power(long long a, long long b, long long mod){
    long long res=1;
    a%=mod;
    while(b>0){
        if(b&1){
            res=(__int128)res*a%mod;
        }
        a=(__int128)a*a%mod;
        b/=2;
    }
    return res;
}

// O(logd +s) = O(log(n-1))= (logn)
bool check_composite(long long n, long long a, long long d, long long s){
    long long x=power(a,d,n);
    if(x==1 || x==n-1){
        return false;
    }
    for(int r=1;r<s;r++){
        x=(__int128)x*x%n;
        if(x==n-1){
            return false;
        }
    }
    return true;
}

// O(12*logn)
bool MillerRabin(long long n){    // if n is prime , then return true
    if(n<2){
        return false;
    }

    int s=0;
    long long d=n-1;
    while(d&1==0){
        d>>=1;
        s++;
    }

    for(int a: {2,3,5,7,11,13,17,19,23,29,31,37}){
        if(n==a){
            return true;
        }
        if(check_composite(n,a,d,s)){
            return false;
        }
    }
    return true;
}
























int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    
	return 0;
}