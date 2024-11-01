#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// data structure to find smallest element of stack in O(1)
// by storing element itself with minimum in the stack starting from this element and below
class min_Stack(){
    public:
    stack<pair<int,int>> st;
    void add(int new_elem){
        int newmin=st.empty()?new_elem:min(new_elem,st.top().second);
        st.push({new_elem,new_min});
    }
    int top(){
        return st.top().first;
    }
    void remove(){
        st.pop();
    }
    int minimum(){
        return st.top().second;
    }

}


// MINIMUM QUEUE
// add in s1, remove from s2( if empty, move all s1 into s2), and minimum is minimum of s1,s2

// On average, all operations take O(1)
class min_Queue<int>(){
    public:
    stack<pair<int,int>> s1,s2; // element, min element before and including it

    // adding new element at the back
    void add(int new_elem){
        int newmin=s1.empty()?new_elem:min(new_elem,s1.top().second);
        s1.push({new_elem,newmin});
    }

    // removing from front
    void remove(){
        if(s2.empty()){
            while(!s1.empty()){
                int ele=s1.top().first;
                s1.pop();
                int newmin=s2.empty()?ele:min(ele, s2.top().second);
                s2.push({ele,newmin});
            }
        }
        s2.pop();
    }

    // getting value of front element
    int top(){
        if(s2.empty()){
            while(!s1.empty()){
                int ele=s1.top().first;
                s1.pop();
                int newmin=s2.empty()?ele:min(ele, s2.top().second);
                s2.push({ele,newmin});
            }
        }
        return s2.top().first;
    }
     
    // minimum minimum of the current elements
    int minimum(){
        if(s1.empty() || s2.empty()){
            return (s1.empty()?s2.top().second:s1.top().second);
        }
        else{
            return min(s1.top().second,s2.top().second);
        }
    }
}


// USING THIS IDEA, WE CAN ALSO CREATE MAX STACK, MAX QUEUE OR ANY OTHER TYPE ACCORDINGLY
















// Min Deque
// LINK -> https://codeforces.com/blog/entry/122003
// Idea is same as except that instead of moving all elements, we move only half of them
// Then complexity of each operation will amortized O(1)






