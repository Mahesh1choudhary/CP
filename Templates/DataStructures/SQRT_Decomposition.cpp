#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

/// In general ,if Block size is B,no of blocks=N/B +1, For query we need to do for at max N/B blocks + for B tail elements, so complexity is O(N/B + B);
/// sometimes if we are doing some operation with tail elements, then complexity is O(N/B + B*F), where F is complexity of operation




// for answering range queries in O(root(N)) per query, with a O(N) preprocessing.
// use only when other data structures are not suitable or time complexity is under constraints
class SQRT_Decompostion(){
    //input data
    int n;
    vector<int> a(n);

    // preprocessing
    int len=(int)sqrt(n+0.0) +1; // size of the block and the number of blocks => first block contains 0 to len-1, second -> len to 2*len-1, third -> 2*len -> 3*len-1, and so on
    vector<int> b(len); // computed value of each block as per the given function f
    for(int i=0;i<n;i++){
        b[i/len]=f(a[i]);
        // for sum queries- b[i/len]+=a[i], as f is sum function, etc
    }


    // If a value changes, then only value of block corresponding to the update need to be recomnputed - O(root(N)) or O(1) in some cases
    void update(int i, x){
        //updating value of a[i] by x;
        int ind=i/len;
        for(int j=ind*len;j<=(ind+1)*len-1;j++){
            b[ind]=f(a[j]);
        } 
    }



    // interval [l,r] will contains part of a block + some middle blocks completely+ part of a block
    //answering range queries
    for(; ;){
        int l,r;
        int sum=0; // for sum queries
        for(int i=l;i<=r;){
            if(i%len==0 && i+len-1<=r){
                // if the whole block starting at i belongs to [l,r];
                sum+=b[i/len];
                i+=len;
            }
            else{
                sum+=a[i];
                i++;
            }
        }
    }

    // above method for answering queries has too many divisions , so slow,
    // instead we can calculate the indices of the blocks cl and cr which contains l, r,
    // and loop through blocks cl+1 .... cr-1 with separate processing of the tails in blocks
    // cl and cr.
    int sum=0;
    int cl=l/len , cr=r/len;
    if(cl==cr){
        for(int i=l;i<=r;i++){
            sum+=a[i];
        }
    }
    else{
        for(int i=l;i<=(cl+1)*len-1;i++){
            sum+=a[i];
        }
        for(int i=cl+1;i<=cr-1;i++){
            sum+=b[i];
        }
        for(int i=cr*len;i<=r;i++){
            sum+=a[i];
        }
    }
}


