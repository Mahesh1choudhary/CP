
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// Method 1 -> operator overloading
struct T{
    // conponents
    bool operator<(T a){

    }
}

// we can also overload < operator outside of struct like this
bool operator <(T &a, T &b){
    //
}

map<T,W> mp;
// If need in reverse order
map<T,W,greater<T>> mp;



// Method 2 -> With comparator function

// can also pass by reference cmpr(T &x, T &y)
bool cmpr(T x, T y){
    // custom sorting
}

map<T,W,bool(*)(T &,T &)> mp(cmpr);
//Or
map<T,W,decltype(cmpr)> mp(cmpr)





// Method 3 -> With Functors
struct T{

}

struct cmpr{
    bool operator()(T &x, T &y){
        // custom sorting
    }
}

map<T,W,cmpr> mp;


// Method 4 -> using Lambda Expressions
auto cmpr = [](T &x, T &y){ return /**/};
map<T,W, bool (*)(T &, T &)> mp(cmpr);
//Or
map<T,W,decltype(cmpr)> mp(cmpr)









//  IF WE WANT TO GIVE MORE THAN 2 PARAMETERS AS INPUT TO COMPARE FUNCTION, THEN WE CAN EITHER USE LAMBDA FUNCTION OR USE FUNCTORS FOR THIS PURPOSE -> https://varrunr.wordpress.com/2012/07/30/passing-extra-parameters-to-stl-sort/




