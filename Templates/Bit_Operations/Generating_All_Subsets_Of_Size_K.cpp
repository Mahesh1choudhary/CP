#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// LINK -> https://codeforces.com/blog/entry/82379
// Also called Gosper's hack


// GENERATING NEXT SUBSET
int nxt_subset(int mask){
    int c = mask & -mask;
    int r=mask+c;
    mask= r|(((r^mask)>>2)/c);
    return mask;
}

// GENERATING PREVIOUS SUBSET
int prev_subset(int mask){
    return ~nxt_subset(~mask);
}



// GENERATING ALL K SIZE SUBSETS
int mask=(1<<k)-1;  // setting rightmost k bits
int limit = 1<<n;
while(mask < limit){
    // perfome some work as required
    int c = mask & -mask;
    int r=mask+c;
    mask= r|(((r^mask)>>2)/c);
}


//  WE CAN USE BITSET IF NO ELEMENTS IS HIGH





