#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Later look at this to improve performances -> https://en.algorithmica.org/hpc/algorithms/matmul/

// General case A => m*l, B => l*n , then C=A*B will be m*n
// O(n*l*m)
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B){
    int m=A.size(), n=B[0].size(), l=A[0].size();

    vector<vector<int>> result(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<l;k++){
                result[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    
    return result;

}




// Square matrices => A and B are n*n
// Algorithm => C=A*B => C[i,j]= Sum over k =0 to n of (A[i,k]*B[k,j])
// O(n^3) 
vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B){
    int n=A.size();
    vector<vector<int>> result(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                result[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return result;    
}















// Very good questions
// 1 - https://codeforces.com/problemset/problem/954/F






