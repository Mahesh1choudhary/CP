#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;


// inverse of n under modulo mod
inverse(int n, int mod){
    int p=mod-2;
    int res=1;
    while(p>0){
        if(p%2==1){
            res=(1LL*res*n)%mod;
        }
        n=(1LL*n*n)%mod;
        p/=2;
    }
    return res;
}


//NTT - multiplying two polynomial under modulo without error in answer( if we use normal fft, then there may be error)
// prime modulo of the form =c*power(2,k)+1, also all primes can be written in this form
const int mod = 7340033; // mod =c*power(2,k)+1; mod is prime
const int root = 5;     // power(g,c)%mod;, g= primitive root of mod
const int root_1 = 4404020; // inverse of root modulo mod
const int root_pw = 1 << 20; // power(2,k);

// invert=true-> inverse fourier transform
void fft(vector<int>& a,bool invert) {
    int n=a.size();
    for(int i=1,j=0;i<n;i++) {
        int bit=n>>1;
        for(;j&bit;bit >>= 1)
            j^=bit;
        j^=bit;

        if(i<j)
            swap(a[i],a[j]);
    }

    for(int len=2;len<=n;len<<=1) {
        int wlen=invert?root_1:root;
        for(int i=len;i<root_pw;i<<=1)
            wlen=(int)(1LL*wlen*wlen%mod);

        for(int i=0;i<n;i+=len) {
            int w=1;
            for(int j=0;j<len/2;j++) {
                int u=a[i+j],v=(int)(1LL*a[i+j+len/2]*w%mod);
                a[i+j]=u+v<mod ? u+v : u+v-mod;
                a[i+j+len/2]=u-v>=0 ? u-v : u-v+mod;
                w=(int)(1LL*w*wlen%mod);
            }
        }
    }

    if(invert){
        int n_1=inverse(n,mod);
        for(int& x:a)
            x=(int)(1LL*x*n_1%mod);
    }
}
 
 
// for arbitrary modulo - to be done



// function for multiplying two polynomials under prime modulo
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++)
        a[i] =(1LL*a[i]*b[i])%mod;
    fft(a, true);
    return a;
}

 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	
	
	
	return 0;
}











// Q1 - https://codeforces.com/problemset/problem/993/E