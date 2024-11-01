#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// LINK -> https://codeforces.com/blog/entry/92918

/* Sorting two or more vectors based on third vector(one of the to be sorted or completely new)
Example -> one vector contains values, other colors, etc, we wanr to sort both based on values in some order

One method is creating a new single vector containing all different vectors -> But this consume lot more memory

Better method is to create a new vector containing indices, and then sort this vector accordingly

*/

vector<int> values, colors;
vector<int> order;  // contain indices from 0 to n-1

sort(order.begin(), order.end(), [&values](int &a, int &b){
    return values[a]<values[b];
});
// using reference to a and b is better especially if a and b are some structs

for(int i=0;i<n;i++){
    int ind=orders[i];
    values[ind], colors[ind]
}



