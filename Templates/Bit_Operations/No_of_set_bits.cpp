
//  CASE 1 -> IF MAXIMUM NO OF BITS IS SAME AS OF INT , LONG LONG , ETC, THEN USE CORRESPONDING BUILD_IN_POP_COUNT
// Method -> using respective __build_in_pocount
// LINK 1 - https://codeforces.com/blog/entry/13134
// LINK 2 - https://codeforces.com/blog/entry/59268

/*
if using __builtin_popcount methods, use these pragmas to make it faster
from LINK1
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")

*/

// Method 2 - calculating manual or can do precalculation - not very optimal
int cnt=0;
for(int i=0;i<31;i++){
    if((n>>i)&1) cnt++;
}






/*
use __buildin_popcount = for int
__builtin_popcountl = for long int
__builtin_popcountll = for long long 

if usint builtin_popcount for long long , then there will be errors

*/





// CASE 2 -> IF MAX NO OF BITS IS LESS THAN THAT OF INT, ETC. LIKE 8 OR 10, EXAMPLE ARE WHEN CHEKING SUBMASKS OF A MASK OF 8 BITS, 10 BITS ETC
// method 1 - using build_in_popcount   - less efficient as it will check all 31 bits in case of int


// more efficient
// method 2 - precalculating no of set bits for each submask
int vals[(1<<n)]; // n=10,15, something, but not 28,30 etc which are same as that of int
for(int i=0;i<(1<<n);i++){
    vals[i]= __builtin_popcount(i);
}



