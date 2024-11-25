#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// mex of an array of size n can never be bigger than n itself


//ALGORITHM 1 -> O(nlogn) using set
int mex(vector<int> &A){
    set<int> st;
    for(int i=0;i<n;i++) st.insert(A[i]);
    for(int i=0;i<=n;i++){
        if(st.count(i)==0){
            return i;
        }
    }
}

// ALGORITHM 2 -> o(n) using boolean vector
int mex(vector<int> &A){
    vector<bool> present(n+1,false);
    for(int i=0;i<n;i++){
        if(A[i]<=n) marked[A[i]]=true;
    }
    for(int i=0;i<=n;i++){
        if(marked[i]==false){
            return i;
        }
    }
}




//  MEX  with array updates

// Method 1 -> LINK - https://codeforces.com/blog/entry/81287?#comment-677837
// O(nlogn) precomputation, O(logn) update and O(1) finding the mex


struct MEX{
    set<int> missing_numbers;
    map<int,int> frequency; // or can use an array of size n+1 as a number greater than n doesn't matter
    vector<int> A;

    // if A{i}>n, then we can completely ignore there effect (not done in below code)
    MEX(vector<int> &B){
        A=B;
        for(int i=0;i<=A.size();i++){
            missing_numbers.insert(i);
        }
        for(int x:A){
            frequency[x]++; 
            missing_numbers.erase(x);
        }
    }

    int mex(){
        return *missing_numbers.begin();
    }

    void update(int index, int new_value){
        frequency[A[index]]--;
        if(frequency[A[index]]==0){
            missing_numbers.insert(A[index]);
        }
        A[index]=new_value;
        frequency[new_value]++;
        missing_numbers.erase(new_value);
    }


}



// segment tree approach for subarray mex quesries - check question 1
// Link 1- https://codeforces.com/blog/entry/84024?#comment-714175



















/*
Good Questions

1- https://codeforces.com/problemset/problem/1436/E


*/




















