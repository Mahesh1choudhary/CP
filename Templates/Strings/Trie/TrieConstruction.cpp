#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

int k=26; // no of different characters appearing in strings
struct vertex{
    vector<int> next; // stores the next index to which proceed with given char
    bool found=false; // ntrue if a string ends at this vertex

    /* optional -> to maintain ids of all the string that ends at this vertex
    vector<int> string_ids;
    Or to maintain count of strings ending at this vertex , we can maintain cnt variable
     if want to keep only one id - can use int instead of vector
    */

    vertex(){
        next=vector<int>(k);
        fill(next.begin(), next.end(),-1);
    }
};


struct trie{
    vector<vertex> tr;
    trie(){
        tr=vector<vertex>(1);
    }

    // O(size of string s)
    void addstring(string s){
        int v=0;
        for(char ch:s){
            int c=ch-'a';
            if(tr[v].next[c]==-1){
                tr[v].next[c]=tr.size();
                tr.emplace_back();
            }
            v=tr[v].next[c];
        }
        tr[v].found=true;
    }
    
    // O(size if string s)
    bool findstring(string s){
        int v=0;
        for(char ch:s){
            int c=ch-'a';
            if(tr[v].next[c]==-1){
                return false;
            }
            v=tr[v].next[c];
        }
        if(tr[v].found){
            return true;
        }
        return false;
    }
};

// time complexity of inserting n string with total length m => O(m), memory complexity O(m*k)
// we can decrease memory to O(m) by using map instead of vector in each vertex , but this will increase time complexity to O(mlogk)
// but if we use unordered map, then it won't increase time complexity


int main(){

    

    return 0;
}