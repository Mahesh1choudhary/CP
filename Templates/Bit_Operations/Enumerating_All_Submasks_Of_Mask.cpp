#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Link -> https://cp-algorithms.com/algebra/all-submasks.html


// Enumerating all submasks of a given mask s
// below code will enumerate submasks in decreasing order- highest value submask first, then smaller and so on.

// O(number of submasks) = O(2^k) where k= no of enabled/set bits
for(int s=mask; ; s=(s-1)&mask){
    // do as per question
    
    // break when s will reach 0, otherwise it will enter a infinite loop
    if(s==0){
        break;
    }
}






// ITERATING THROUGH ALL MASKS WITH THEIR SUBMASKS
// O(3^n) , n elements or total n bits

for(int mask=0; mask<(1<<n); mask++){
    for(int s=mask; ; s=(s-1)&mask){
        //
        if(s==0){
            break;
        }
    }
}











