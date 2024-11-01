#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// LINK -> https://codeforces.com/blog/entry/96699


/* There are two approaches to it - in terms of start and end point
Approach 1 -> when we just need to find a index where some condition is met
then if we set start and end, then they are included in the range, i.e. [start,end]

Approach 2 -> if we need to find first index satisfying a condition like upper bound, or first false in array of type [ true...., false.....],
then we can either use appraoch 1, but in this case we need to use extra variable as answer
because  
while(start<=ed){
    int mid=strt+(ed-strt)/2;
    if(condition is met){
        strt=mid+1;
    }
    else{
        ed=mid-1;
    }
} 
here we are always adding or subtracting 1, so if mid is the answer we will never get the correct answer, so we need to use extra variable
if we set strt=mid, then there will be error as at some point strt = strt+(ed-strt)/2 eg(strt=1, ed=2), so infinite loop

The approach 1 with extra variable can be used in such cases,
But in such cases , better appraoch is to set start and end condition such that included range is (start, end)
then loop becomes
while(ed-strt>1){
    int mid= strt+(ed-strt)/2;
    if(condition is met){
        strt=mid;
    }
    else{
        ed=mid;
    }
}
return ed or strt accordingly


*/








// BINARY SEARCH ON REAL VALUES
// INSTEAD OF DOING (l-r>0.0001) SOMETHING , USE NO OF ITERATIONS

int count=300;
double strt=0, ed=1000.0;
for(int i=0;i<count; i++){
    double mid=strt+(ed-strt)/2;
    if(check(mid)){
        r=mid;
    }
    else strt=mid;
}

// Better appraoch for binary search on real values 
// LINK -> https://codeforces.com/blog/entry/63085







