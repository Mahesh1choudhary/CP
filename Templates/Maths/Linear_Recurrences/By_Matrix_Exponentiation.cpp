#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// Find F(n)
// O((k^3)logn) -> LINK -> https://zobayer.blogspot.com/2010/11/matrix-exponentiation.html
// If need to do under modulo p, then same method , just take modulo for every multiply
vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B){
    int n=A.size();
    vector<vector<int>> dummy(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dummy[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return dummy;
}

// A^n
vector<vector<int>> matrix_Exponentiation(vector<vector<int>> A, n){
    int k=A.size();
    vector<vector<int>> ans(k,vector<int>(k,0));    // identity matrix
    for(int i=0;i<k;i++){
        ans[i][i]=1;
    }
    while(n>0){
        if(n&1){
            ans=multiply(A, ans);
        }
        A=multiply(A,A);
        n/=2;
    }
    return ans;
}

int findFn(){

    vector<int> base_cases(k);  // F[k-1], F[k-2].....F[0];

    vector<vector<int>> An=matrix_Exponentiation(A,n);
    int k=An.size();
    int ans=0;
    for(int i=0;i<k;i++){
        ans+=An[0][i]*base_cases[i];
    }
    return ans;
}








// FOR ARRAYS
const int maxm=5;

long long mat[maxm][maxm], dummy[maxm][maxm], res[maxm][maxm];

void multiply(int type,long long mod){
    
    for(int i=0;i<maxm;i++)for(int j=0;j<maxm;j++) dummy[i][j]=0;
    
    if(type==0){
        for(int i=0;i<maxm;i++){
            for(int j=0;j<maxm;j++){
                for(int k=0;k<maxm;k++){
                    dummy[i][j]=(dummy[i][j]+mat[i][k]*mat[k][j])%mod;
                }
            }
        }
        
        for(int i=0;i<maxm;i++)for(int j=0;j<maxm;j++) mat[i][j]=dummy[i][j];
    
    }
    else{
        for(int i=0;i<maxm;i++){
            for(int j=0;j<maxm;j++){
                for(int k=0;k<maxm;k++){
                    dummy[i][j]=(dummy[i][j]+mat[i][k]*res[k][j])%mod;
                }
            }
        }
        for(int i=0;i<maxm;i++)for(int j=0;j<maxm;j++) res[i][j]=dummy[i][j];
    
    }
}

void matrix_Exponentiation(long long b, long long mod){
    for(int i=0;i<maxm;i++){
        res[i][i]=1;
    }
    while(b>0){
        if(b&1){
            multiply(1,mod);
        }
        multiply(0,mod);
        b/=2;
    }
}

long long power(long long a, long long b,long long mod){
    long long res=1;
    while(b>0){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}














// MATRIX CLASS CREATION -  https://codeforces.com/problemset/submission/1182/55478881





