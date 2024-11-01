#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// LINK -> https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
// GENERAL CASE-> MATRIX SIZE IS M*N
/*
Given n equation in m vaurables
    a11*x1 + a12*x2 ..... a1m*xm=b1
    .
    .
    an1*x1 + an2*x2 ..... anm*xm = bn

    This method can also be used to solve equation given in mod p  
    a11*x1 + a12*x2 ..... a1m*xm = b1   (mod p)
    .
    .
    an1*x1 + an2*x2 ..... anm*xm = bn   (mod p)


BASIC ALGORITHM
divide first row by a11, then using this make ai1 of all other rows to 0 by multiply with -ai1 and adding
we do this for all columns

If aii is zero, we select some other row with nonzero value of i the columns

even if aii!=0, we swap i th row with maximum absolute value of aji, to reduce the error in answer

If all the valuesin the columns are zero, then we skip this column and move on. In this case either xi has no solution or is independent variable and can take arbitrary value.

when no of variables m are greater than number of equations n, then atleast m-n independent variables will be found

Even when there are independent variables, SLAE can have no solution at all.
*/


// In below implementation, pivot row is chosen with heuristic: choosing maximum value in the current column.

double EPS= 1e-9;
int INF =2 ;    // if infinitely many solutions, then we will return this value

// O(min(n,m)*nm);
int gauss(vector<vector<double>> a, vector<double> &ans){
    int n = a.size();
    int m= (int)a[0].size()-1;  // as last column contains b

    vector<int> where(m, -1);   // for each column, to store corresponding rows with non-zero a[row][col] - needed as some variables can be independent
    for(int col=0, row=0; col<m && row<n; col++){
        
        int sel=row;   // row number with maximum absolute value of a[row][col]
        for(int i=row;i<n;i++){
            if(abs(a[i][col])>abs(a[sel][col])){
                sel=i;
            }
        }

        // if found row has a[sel][col]=0, then it is considered as independent variable and move on
        if(abs(a[sel][col])<EPS){
            continue;
        }

        // swaping the current row with feound row sel
        for(int i=col;i<=m;i++){
            swap(a[sel][i], a[row][i]);
        }
        where[col]=row;

        // substracting from all other rows
        for(int i=0;i<n;i++){
            if(i!=row){
                double c= a[i][col]/a[row][col];
                for(int j=col;j<=m;j++){
                    a[i][j]-=a[row][j]*c;
                }
            }
        }
        row++;
    }


    ans.assign(m,0);
    // finding answer
    for(int i=0;i<m;i++){
        if(where[i]!=-1){
            ans[i]=a[where[i]][m]/a[where[i]][i];   // xi=b/aii
        }
    }

    // checking no of solutions - 0,1, infinite
    
    //checking 0 solution ->  putting found answers answers on each equations and checking whether eqaution sum to 0
    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<m;j++){
            sum+=ans[j]*a[i][j]
        }
        if(abs(sum-a[i][m])>EPS){
            return 0;
        }
    }

    // checking infinte solutions
    for(int i=0;i<m;i++){
        if(where[i]==-1){
            return INF;
        }
    }
    
    // otherwise one solution given ans;
    return 1;

}


// LINK ->  https://codeforces.com/blog/entry/66687
// UNDER PRIME MODULO mod -> In this case , all elements should be int, as we will use inverses in place of divide
// We can either make all elements positive before calculations, or can do when required
int gauss(vector<vector<int>> a, vector<int> &ans){
    int n = a.size();
    int m= (int)a[0].size()-1;  // as last column contains b

    vector<int> where(m, -1);   // for each column, to store corresponding rows with non-zero a[row][col] - needed as some variables can be independent
    for(int col=0, row=0; col<m && row<n; col++){
        
        int sel=row;   // row number with maximum absolute value of a[row][col]
        for(int i=row;i<n;i++){
            if(abs(a[i][col])>abs(a[sel][col])){
                sel=i;
            }
        }

        // if found row has a[sel][col]=0, then it is considered as independent variable and move on
        if(abs(a[sel][col])==0){
            continue;
        }

        // swaping the current row with feound row sel
        for(int i=col;i<=m;i++){
            swap(a[sel][i], a[row][i]);
        }
        where[col]=row;

        // substracting from all other rows
        for(int i=0;i<n;i++){
            if(i!=row){
                int c=(a[i][col]*inverse(a[row][col]))%mod;
                c=(c+mod)%mod;  // if matrix elements are not made positive beforehand
                for(int j=col;j<=m;j++){
                    a[i][j]-=a[row][j]*c%mod;
                    a[i][j]=(a[i][j]%mod+mod)%mod;
                }
            }
        }
        row++;
    }


    ans.assign(m,0);
    // finding answer
    for(int i=0;i<m;i++){
        if(where[i]!=-1){
            ans[i]=a[where[i]][m]*inverse(a[where[i]][i])%mod;   // xi=b/aii
            ans[i]=(ans[i]+mod)%mod;    // if matrix elements are not made positive beforehand
        }
    }

    // checking no of solutions - 0,1, infinite
    
    //checking 0 solution ->  putting found answers answers on each equations and checking whether eqaution sum to 0
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum=(sum+ans[j]*a[i][j]%mod)%mod;
            sum=(sum+mod)%mod;

        }
        if(abs(sum-a[i][m])!=0){
            return 0;
        }
    }

    // checking infinte solutions
    for(int i=0;i<m;i++){
        if(where[i]==-1){
            return INF;
        }
    }
    
    // otherwise one solution given ans;
    return 1;

}















//  IF MODULO IS 2, THEN USING BITSETS AND BIT OPERATIONS, ALGORITHM CAN BE MADE 32 TIMES FASTER

int gauss (vector < bitset<N> > a, int n, int m, bitset<N> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
        // The rest of implementation is the same as above
}








