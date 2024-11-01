#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// This trie structure is very useful for XOR related queries
// Link for Questions patterns-https://threadsiiithyderabad.quora.com/Tutorial-on-Trie-and-example-problems

// Trie can store information about keys/numbers/strings compactly in tree;
// tries consists of nodes, where each node stores a character/bit. We can insert strings/numbers accordingly

/*
Problem1: Given an array of integers, we have to find two elements whose XOR is maximum.
Solution:
Suppose we have a data structure which can satisfy two types of queries:
1. Insert a number X
2. Given a Y, find maximum XOR of Y with all numbers that have been inserted till now.

If we have this data structure, we'll insert integers as we go, and with query of 2nd type we'll find the maximum XOR.
Trie is the data structure we'll use.
Insertion of a new key N is takes log(N), as their are log(N) in a number
For insertion ans query we convert each number into constant bit size(32 or 64, etc) by padding zeros in front
Query is also log(M), if we need to find maximum xor of M with available numbers
*/





// In this implementation of trie, we will keep nodes and left and right pointers
// we will keep zero on left and 1 on right

// IMPLEMENTATION DETAILS -> https://github.com/ShahjalalShohag/code-library/blob/master/Data%20Structures/Trie.cpp
// RECHECK CODE FROM SOURCE LINK AS GIVEN ABOVE
struct node{
    int sz=0; // number of element which contains this bit
    node* nxt[2]; // left and right pointers
    node(){
        nxt[0]=nxt[1]=NULL;
    }
};

int B=31; ///   maximum number of bits in number given as input
struct Trie{
    node root;
    Trie(){
        root=node();
    }

    void insert(int val){
        node* cur=&root;
        cur->sz++;
        for(int i=B-1;i>=0;i--){
            int b=val>>i&1;
            if(cur->nxt[b]==NULL) cur->nxt[b]=new node();
            cur=cur->nxt[b];
            cur->sz++;
        }
    }

    int query(int x, int k){ // number of values such that val^x<k
        // we can change this query function as per need
        node* cur=&root;
        int ans=0;
        for(int i=B-1;i>=0;i--){
            if(cur==NULL) break;
            int b1=x>>i&1, b2=k>>i&1;
            if(b2==1){
                if (cur->nxt[b1]) ans+=cur->nxt[b1]->sz;
                cur=cur->nxt[!b1];
            } else cur=cur->nxt[b1];
        }
        return ans;
    }
    int get_max(int x) { // returns maximum of val ^ x
        node* cur=&root;
        int ans=0;
        for(int i=B-1;i>=0;i--) {
            int k=x>>i&1;
            if(cur->nxt[!k])cur=cur->nxt[!k], ans<<=1, ans++;
            else cur=cur->nxt[k], ans<<=1;
        }
        return ans;
    }
    int get_min(int x) { // returns minimum of val ^ x
        node* cur=&root;
        int ans=0;
        for (int i=B-1; i>=0; i--) {
            int k=x>>i&1;
            if(cur->nxt[k]) cur=cur->nxt[k], ans<<=1;
            else cur=cur->nxt[!k], ans<<=1, ans++;
        }
        return ans;
    }
    void del(node* cur) {
        for (int i=0; i<2; i++) if(cur->nxt[i]) del(cur->nxt[i]);
        delete(cur);
    }
};




// Array based implementation
// has errors

int B=31;
struct vertex{
    vector<int> next; // stores the next index to which proceed with given char
    int sz=0;  //

    vertex(){
        next=vector<int>(2,-1);
    }
};


struct trie{
    vector<vertex> tr;
    trie(){
        tr=vector<vertex>(1);
    }

    // O(B)
    void insert(int n){
        int v=0;
        tr[v].sz++;
        for(i=B;i>=0;i--){
            int b=((n>>i)&1);
            if(tr[v].next[b]==-1){
                tr[v].next[b]=tr.size();
                tr.emplace_back();
            }
            v=tr[v].next[b];
            tr[v].sz++;
        }
    }
    
    // O(B)
    int query(int x, int k){ // number of values such that val^x<k
        // we can change this query function as per need
        int v=0;
        int ans=0;
        for(int i=B-1;i>=0;i--){
            if(v=tr[v].sz==0) return;
            int b1=((x>>i)&1), b2=((k>>i)&1);
            if(b2==1){
                if(tr[v].next[b1]!=-1) ans+=tr[v].next[b1].sz;
                v=tr[v].next[!b1];
            }
            else{
                v=tr[v].next[b1];
            }
            
        }
        return ans;
    }
};

// time complexity of inserting n string with total length m => O(m), memory complexity O(m*k)
// we can decrease memory to O(m) by using map instead of vector in each vertex , but this will increase time complexity to O(mlogk)


int main(){

    

    return 0;
}









// GOOD TRIE QUESTIONS 
// 1 - https://codeforces.com/problemset/problem/842/D
// 2 - https://codeforces.com/problemset/problem/665/E













