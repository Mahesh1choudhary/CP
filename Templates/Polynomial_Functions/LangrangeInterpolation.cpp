#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// To solve questions that are solvable using this technique, just find the degree of equation let it be x, then we need to find out first x+1 points only
// given f(xi)=yi, for 1<=i<=n, find f(x) for some random x, here f is of degree n-1

/*
f(x)=∑(i=1 to n : yi(∏ j=1 to n,j≠i :x−xj/xi−xj));

*/







//CASE-1: if xi are of the form 1,2,3,4,...n =? so we have n points ,so egree will be n-1
// LINK -> https://codeforces.com/blog/entry/82953
// even if xi are a,a+1,....a+n-1, then also we can solve using this, just need to change the prefix and suffix sums accordingly

long long nmax=1e6,mod=1e9+7;
vector<long long> factorial(nmax,1);
vector<long long> modinverse(nmax,1);

long long power(long long a,long long b){
    long long res=1;
    while(b>0){
        if(b%2==1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}

// O(n), if inverses are precalculated or O(nlog(mod)) if calculating during need
void interpolate1(int x){
    vector<int> xi(n+1),yi(n+1);//xi[0] and yi[0] are empty, x1 to xn are points and y1 to yn are corresponding results at these points
    
    // precalculate the suffix and prefix of numerator terms to answer quickly
    vector<int> prefix(n+2,1),suffix(n+2,1);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]*(x-i);
        suffix[n+1-i]=(x-n-1+i)*suffix[n+1-i+1];
    }
    long long ans=0;
    for(long long i=1;i<=n;i++){
        long long val1=(prefix[i-1]*suffix[i+1])%mod;
        long long val2=modinverse[(factorial[n-i]*factorial[i-1])%mod];
        if((n-i)%2==1){
            ans-=yi[i]*((val1*val2)%mod)%mod;
        }
        else{
            ans+=yi[i]*((val1*val2)%mod)%mod;
        }
        ans%=mod;
    }
    if(ans<0){
        ans+=mod;
    }
    return ans;
}

int main(){

    for(int i=1;i<=nmax;i++){
        factorial[i]=(i*factorial[i-1])%mod;
        modinverse[i]=power(i,mod-2);
    }

    return 0;
}









// CASE 2 -> for general xi's i.e. when xi's are not linear ->  general brute can be done in O(n^2) as said in above link
// using this method, we can also interpolate multiple values, i.e. given f(x) and x1,x2,...xn , we can find f(x1), f(x2)....f(xn)
// LINK -> https://codeforces.com/blog/entry/94143
// O(n*(logn)^2)












