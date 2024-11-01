#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;


// For calculating divisors of all numbers from one to n

// Method 1 -> try to find divisor of each number i int sqrt(i)
// n*sqrt(n)

vector<vector<int>> divisors(n+1);
for(int i=2;i<=n;i++){
    for(int j=1;j*j<=n;j++){
        if(i%j==0){
            divisors[i].push_back(j);
        }
    }
    divisors.push_back(i);  // i is divisor of i
}




// Method 2 -> using harmonic lemma
// O(nlogn)
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i){
        divisors[j].push_back(i);
    }
}








