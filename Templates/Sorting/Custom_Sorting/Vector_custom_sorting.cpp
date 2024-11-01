
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// Method 1->  With comparator function

void cmpr(T a, T b){
    // of two element , the element that satisfies condition is put first, then second element
}

// vector with elements of type T
vector<T> v;
sort(v.begin(), v.end(), cmpr);




// Method 2 ->  Operator Overloading

struct T{
    // its components

    // define operator on elements
    bool operator < (T a){
        //
    }
}

// we can also overload < operator outside of struct like this
bool operator <(T &a, T &b){
    //
}



vector<T> v;
sort(v.begin(), v.end());
// If need in reverse order
sort(v.begin(), v.end(), greater<T>());




// Method 3 -> Using Functors
struct T{

}

struct cmpr{
    bool operator ()(T &a, T &b){
        //
    }
}
 vector<T> v;
 sort(v.begin(), v.end(), cmpr());


// Method 4 - Using lamda functions
vector<T> v;
sort(v.begin(), v.end(), []( T &a, T &b){ return /**/});








//  IF WE WANT TO GIVE MORE THAN 2 PARAMETERS AS INPUT TO COMPARE FUNCTION, THEN WE CAN EITHER USE LAMBDA FUNCTION OR USE FUNCTORS FOR THIS PURPOSE -> https://varrunr.wordpress.com/2012/07/30/passing-extra-parameters-to-stl-sort/


