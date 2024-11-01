#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Properties of GCD and LCM - https://www.cut-the-knot.org/arithmetic/GcdLcmProperties.shtml
// GCD property - In editorial - https://codeforces.com/problemset/problem/837/E   -  One important fact is that when we subtract gcd(x, y) from y, new gcd(x, y) will be divisible by old gcd(x, y). And, of course, x is always divisible by gcd(x, y)



// O(log(min(a,b)))
int gcd(int a, int b){
    while(b>0){
        a=a%b;
        swap(a,b);
    }
    return a;
}




// to find x and y such that a*x+b*y=gcd(a,b)

// base cas when b=0, the  x=1, y=0;
// if x1, y1 are coefficients of (b, a mod b), and x,y for (a,b)
// then  x= y1, y=x1-y1*(a/b);

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


// WHEN WE FIND gcd OF N NUMBERS, THEN TIME COMPLEXITY IS O(n+log(amax)), NOT O(n*log(amax)), because
// at each step gcd of numbers will either decrease by atleast 2 or remian same


// LCM of Fibonaci numbers - https://www.hackerrank.com/contests/infinitum10/challenges/fibonacci-lcm/editorial









