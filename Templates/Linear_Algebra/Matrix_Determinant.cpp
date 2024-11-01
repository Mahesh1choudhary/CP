#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;


// ideas is same as guassian eleimination ,we first convert matrix into diagonal matrix and then multiply all diagonal elements
// Also, we need to keep track of swaps, as odd no of swaps, changes the sign of determinant

double EPS = 1e-9;

int find_determinant(vector<vector<double>> &a){
    int n=a.size();

    double det=1;
    for(int i=0;i<n;i++){
        int sel=i;    // as col=row in swaure matrix
        for(int j=i;j<n;j++){
            if(abs(a[j][i]>abs(a[sel][i]))){
                sel=j;
            }
        }
        

        // if a complete column is zeros, then determinant is zero
        if(abs(a[sel][i])<EPS){
            det=0;
            break;
        }

        swap(a[i], a[k]);

        // swap changes sign of determinant
        if(i!=sel){
            det=-det;
        }

        det*=a[i][i];
        // substracting from remaining rows
        for(int j=i+1;j<n;j++){
            a[i][j]/=a[i][i];
        }
        for(int j=0;j<n;j++){
            if(j!=i && abs(a[j][i])>EPS){
                for(int k=i+1;k<n;k++){
                    a[j][k]-=a[i][k]*a[j][i];
                }
            }
        }

    }
    return det;
}





