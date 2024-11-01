
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// USE THE EXACT NOTATIONS, OTHERWISE THERE WILL BE ERRORS
// -> LINK FOR EXACT NOTATIONS -> https://usaco.guide/silver/custom-cpp-stl?lang=cpp

// Method 1 -> operator overloading
struct T{
    // components   
    //always use the second const, otherwise there will be errors, first cosnt is optional
    bool operator<(const T a) const {

    }
}


// we can also overload < operator outside of struct like this
bool operator <(const T &a, const T &b){
    //
}


set<T> st;

// If need in reverse order
set<T,greater<T>> st;



// Method 2 -> With comparator function

// can also pass by reference cmpr(T &x, T &y)
bool cmpr(T x, T y){
    // custom sorting
}

set<T,bool(*)(T &,T &)> v(cmpr);    // not sure if works
//Or
set<T,decltype(cmpr)> st(cmpr);    // use exact notations ( i.e. ncecessary to use &)



// Method 3 -> With Functors
struct T{

}

struct cmpr{
    bool operator()(const T &x, const T &y){
        // custom sorting
    }
}

set<T,cmpr> st;


// Method 4 -> using Lambda Expressions
auto cmpr = [](const T &x, const T &y){ return /**/};
set<T, bool (*)(const T &,const T &)> v(cmpr);  // not sure if works
//Or
set<T,decltype(cmpr)> st(cmpr); // with lambda function, do not use & as done in eralier using cmp function








//  IF WE WANT TO GIVE MORE THAN 2 PARAMETERS AS INPUT TO COMPARE FUNCTION, THEN WE CAN EITHER USE LAMBDA FUNCTION OR USE FUNCTORS FOR THIS PURPOSE -> https://varrunr.wordpress.com/2012/07/30/passing-extra-parameters-to-stl-sort/


//IMPORTANT
//set keeps elements on the basis of comparison, if in compare function with parameter pi -> so if two elements have same p parameters  p1=p2, then only one element will be kept in set
//so in such cases , use multiset, or include parameter as part of element too, so that if parameters are same, we can sort using element value OR we can change cmpr fundtion to include case when parameter values are same
// So best is to change compare function accordingly

//eg. -> 
// this will include one pair<int,int> with distinct cnt[p.first][p.second]
auto cmpr=[&](pair<int,int> p1, pair<int,int> p2){
    return cnt[p1.first][p1.second]<cnt[p2.first][p2.second];
}
set<pair<int,int>,decltype(cmpr)> st(cmpr);

// one of the correct way -> change cmpr function to include all
auto cmpr=[&](pair<int,int> p1, pair<int,int> p2)->bool{
    if(cnt[p1.first][p1.second]==cnt[p2.first][p2.second]){
        return p1<p2;
    }
    return cnt[p1.first][p1.second]<cnt[p2.first][p2.second];
}
set<pair<int,int>,decltype(cmpr)> st(cmpr);




