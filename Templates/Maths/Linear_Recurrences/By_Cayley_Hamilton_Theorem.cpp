#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// O((k^2)*logn)
// LINK -> https://discuss.codechef.com/t/linear-recurrence-using-cayley-hamilton-theorem/6776

// M^k = a1*M^(k-1) + a2*M^(k-2) + ... ak*I, this equation is same as characteristic equation of matrix M formed by recurrence
/* We need to know how to compute the representation of :
    1. -> M^(n+1) from M^n
    2. -> M^(2*n) from M^n

    Part 1
    Let M^n => a1*M^(k-1) + a2*M^(k-2) + ... ak*I
    For M^(k+1) = M*M^k => a1*M^(k) + a2*M^(k-1) + ... ak*M
    replacing M^n by a1*M^(k-1) + a2*M^(k-2) + ... ak*I gives
    M^(k+1) => (a1*a1+a2)*M^(k-1) + (a3+a2*a1)*M^(k-2) and so on
    
    So we can find M^n from M^(n-1) in O(k) ->  initial coefficient of M^i will be the coeffient of M^(i+1) for i<=k-2, For M^k just add extra term a1*ai in coefficients of M^(k-1) to I, and add initial terms, 


    Part 2 
    M^(2*n) = (M^n)*(M^n)   -> we can find this O(k*k)
    By replacing M^n with corresponding equation , we get powers of M from 0 to 2*k-2, replace powers of M greater than k-1 with corresponding with their corresponding representation from higher power to lower power
    M^(2k-2) in terms of its characteristic equation which gives power from M^(2k-3) to M^(2k-1-k), add coefficients according , then replace M^(2*k-3) and so on


    With above equations , we can easily do matrix exponentiation in ((k^2)logn)
    
    Finally we will have M^n = b1*M^(k-1)+ ..... bk*I
    Foe finding F(n) we only need to sum the first row of every matrix to get the final row vector -> which can be done in O(k*k)
    With row vector R and bases case vector B, we can find F[n] = sum over all i -> R[i]*B[i] -> here B[0]=base case when n=k-1, B[1] = k-2 and so on
*/



// incomplete
void matrix_exponentiation(vector<int> coeff)













