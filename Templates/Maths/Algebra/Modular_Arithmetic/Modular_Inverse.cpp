#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;


// Link -> https://cp-algorithms.com/algebra/module-inverse.html


// a*x=1 (mod m), then x=a^(-1)= inverse of a under modulo m
// MODULAR INVERSE EXISTS ONLY IF  a AND m ARE COPRIME

// from euler's theorem , a^(phi(m)) = 1 (mod m), and if m is prime phi(m)=m-1;
// so a^-1 = a^(phi(m)-1) (mod m)



////// ======>>> METHODS WHEN  M IS PRIME ( all below methods till non prime case)
// So if m is prime or if prime factorization of m is known, use euler theorem and compute a^(m-2) (mod m)

// O(logm)
long long inverse(long long a, long long m){
    long long res=1;
    long long b=m-2;
    while(b>0){
        if(b&1==1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=(b>>1);
    }
    return res;
}



// Link-https://cp-algorithms.com/algebra/module-inverse.html#finding-the-modular-inverse-for-prime-moduli-using-euclidean-division
// first brought a to less than m by a=a%m
// then  m=k*a+r , taking mod by m gives 0=k*a+r, where k=m/a and r=m%a
// overall a^-1 = -k*(r^-1);
// valid only when m is prime -   O(m^(1/3), but generally very fast

int inv(int a,m){
    if(a<=1){
        return a;
    }
    else{
        return m - (long long)(m/a)*inv(m%a, m)%m;
    }
}

// we can use above algorithm to precompute modular inverse for every number in range 1 to m-1 in O(m)
// modular number for a>m = modular inverse of (a%m)
vector<int> inv(m);
inv[1]=1;
for(int a=2;a<m;a++){
    inv[a]=m-(long long)(m/a)*inv[m%a]%m;
}


// For n random numbers - modular inverse in O(n+logp)
// LINK - https://codeforces.com/blog/entry/83075

















///// ========>>> METHODS WHEN M IS NOT PRIME
// otherwise if m is not prime, use extended euclid algorithm as computing phi(m) is costly comparatively
// a*x + m*y =1, then ax=1(mod m), so a^(-1) = x  (mod m)

// Other interpretation-treat it like ax=b (mod m), where b =1, then it is linear congruence relation

int extended_gcd(int a, int b, int& x, int& y){
    if(b==0){
        x=1, y=0;
        return a;
    }
    int x1, y1;
    int d=extended_gcd(b, a%b, x1, y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

int inverse(int a, int m){
    int x,y;
    int g=extended_gcd(a,m,x,y);
    if(g!=1){
        cout<<"no solution"<<endl;
    }
    else{
        x=(x%m + m)%m;
        cout<<x<<endl;
    }

}



// to find modular inverse of all numbers from 1 to n, we have to find it separately for each so O(nlogn)






