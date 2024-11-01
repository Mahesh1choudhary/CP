#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// Method 3 is best -> we can also combie method 3 with (N^(1/3)) given in counting no of divisors template 



// METHOD 1 => TRIAL DIVISION - O(sqrt(n))
// we divide by each possible divisor, we only need to test the divisors 2<= d <= root(n)
//If we cannot find any divisor in the range [2, sqrt(n)] , then the number itself has to be prime.
vector<long long> trial_division(long long n){
    vector<long long> prime_fac;
    for(long long d=2; d*d<=n;d++){
        while(n%d==0){
            n/=d;
            prime_fac.push_back(d);
        }
    }
    if(n>1){
        prime_fac.push_back(n);
    }
    return prime_fac;
}


// METHOD 2 => PRECOMPUTED PRIMES -  precompute all prime numbers with the Sieve of Eratosthenes until sqrt(n) and test them individually.
// O(root(n)loglogn), but runs faster than method 1
vector<long long> trial_division(long long n){
    vector<long long> prime_fac;
    for(long long d:primes){
        if(d*d>n){
            break;
        }
        while(n%d==0){
            n/=d;
            prime_fac.push_back(d);
        }
    }
    if(n>1){
        prime_fac.push_back(n);
    }
    return prime_fac;
}





// METHOD 3 => Pollard's rho algorithm - O((n^(1/4))*logn)
// LINK 1 - https://cp-algorithms.com/algebra/factorization.html#pollards-p-1-method
// LINK 2 - https://morris821028.github.io/2015/07/11/uva-11476/

long long gcd(long long a, long long b){
    while(b>0){
        a%=b;
        swap(a,b);
    }
    return a;
}

long long mult(long long a, long long b, long long mod){
    return (__int128)a*b %mod;
}

/*
use if __int128 is not supported by compiler
long long mult(long long a, long long b, long long mod){
    long long res=0;
    while(b>0){
        if(b&1){
            res=(res+a)%mod;
        }
        a=(a+a)%mod;
        b/=2;
    }
    return res;
}
*/

// If numbers a and b are small (<1e9)
long long small_power(long long a, long long b, long long mod){
    long long res=1;
    a%=mod;
    while(b>0){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return res;
}



// Miller Robin to test primality
// Implementation for numbers upto 64 bits
// O(logb)
long long power(long long a, long long b, long long mod){
    long long res=1;
    a%=mod;
    while(b>0){
        if(b&1){
            res=mult(res,a,mod);
        }
        a=mult(a,a,mod);
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
        x=mult(x,x,n);
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

    long long s=0;
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






// to calculate polynomial function x*x+c
long long f(long long x, long long c, long long mod){
    return (mult(x,x,mod)+c)%mod;
}


// Using Floyd's cycle finding algorithm
long long rho(long long n, long long x0=2, long long c=1){
    long long x=x0, y=x0;
    long long g=1;
    while(g==1){
        x=f(x,c,n);
        y=f(y,c,n);
        y=f(y,c,n);
        g=gcd(abs(x-y),n);
    }
    return g;
}

// using brent's cycle finding algorithm - it is faster than Floyd's method
long long brent(long long n, long long xo=2, long long c=1){


}

vector<long long> prime_factors;    // to store prime factorization

// trial divison for smaller numbers( <1e9)
// we can also precompute prime till root(1e9) to speed up process
void trial_division(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            prime_factors.push_back(i);
            n/=i;
        }
        
    }
    if(n>1){
        prime_factors.pb(n);
    }
}



void factorize(long long n){

    if(n==1){
        return;
    }
    if(n<1e9){
        trial_division(n);
        return;
    }
    if(MillerRabin(n)){
        prime_factors.push_back(n);
        return;
    }

    long long g=n;
    for(long long i=2;g==n;i++){
        g=rho(n,i);
    }

    factorize(g);
    factorize(n/g);

}





















// METHOD -4 => IF WE WANT TO COMPUTE FACTORIZATION FOR MANY NUMBERS


// Link: https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/\

// Prime factorization in O(logx) with precomputation in O(nloglogn).

//The main idea is to precompute the Smallest Prime Factor (SPF) for each number from 1 to MAXN 
// using the sieve function. SPF is the smallest prime number that divides a given number without
// leaving a remainder.

void Prime_fact(){
    vector<int> spf(n+1);
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }

    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }

    // finding prime factors of x;
    vector<int> factors;
    int x;
    while(x>1){
        factors.pb(spf[x]);
        int p=spf[x];
        while(x%p==0){
            x/=p;
        }
    }


}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    
	return 0;
}