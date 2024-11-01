#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;


// a*x=b (mod n);
// If a and n are coprime, then there is one solution x=a^(-1) * b;
// otherwise, let g=gcd(a,n), if b is not divisible by g, then there is no solution, otherwise there are g solutions given by  solving a'*x'=b' (mod n')
// where a' = a/g, b' =b/g, n' = n/g,   and xi=(x'+i*n') (mod n) for i=0,...g-1
// so the 








