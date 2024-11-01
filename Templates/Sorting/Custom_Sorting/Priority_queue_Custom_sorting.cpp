
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// Method 1 -> operator overloading
struct T{
    // components
    bool operator<(T a){
        //
    }
}

// we can also overload < operator outside of struct like this
bool operator <(T &a, T &b){
    //
}

priority_queue<T> pq;
// If need in reverse order
priority_queue<T,vector<T>, greater<T>> pq;



// Method 2 -> With comparator function

// can also pass by reference cmpr(T &x, T &y)
bool cmpr(T x, T y){
    // custom sorting
}

priority_queue<T,vector<T>, bool(*)(T &, T &)> pq(cmpr);
//Or
priority_queue<T,vector<T>, decltype(cmpr)> pq(cmpr);




// Method 3 -> With Functors
struct T{

}

struct cmpr{
    bool operator()(T &x, T &y){
        // custom sorting
    }
}

priority_queue<T,vector<T>, cmpr> pq;


// Method 4 -> using Lambda Expressions
auto cmpr = [](T &x, T &y){ return /**/};

priority_queue<T,vector<T>, bool(*)(T &, T &)> pq(cmpr);
//Or
priority_queue<T,vector<T>, decltype(cmpr)> pq(cmpr);


// FOR PRIORITY QUEUE, IF WE WNAT A CERTAIN ORDER, THEN THE COMPARE FUNCTION SHOULD BE COMPLETELY OPPOSITE OF THAT ORDER
// FOR EXAMPLE, IF WE WANT MIN PRIORITY QUEUE, THEN COMPARE FUNCTION SHULD BE -> 
// cmpr(int a, int b) return a>b








//  IF WE WANT TO GIVE MORE THAN 2 PARAMETERS AS INPUT TO COMPARE FUNCTION, THEN WE CAN EITHER USE LAMBDA FUNCTION OR USE FUNCTORS FOR THIS PURPOSE -> https://varrunr.wordpress.com/2012/07/30/passing-extra-parameters-to-stl-sort/

