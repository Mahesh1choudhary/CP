#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// Link( below implementation)-> https://usaco.guide/gold/tree-euler?lang=cpp


// Main idea -> Flattening a tree into an array to easily query and update subtrees
// Once we find the euler, we can answer queries building using segment tree, sparse table, BIT whichever suits best
// we will data structure on euler tour

// problem to look out for or handle separately -> a tree of size one has euler tour of size 0

int n;
int timer=0;
vector<int> tin, tout;
vector<vector<int>> graph;

// for subtree queries we only need tin, but for path queries( we can't do all type of queries, only some possible) we need both tin and tout


void euler_tour(int curr, int parent){
    tin[curr]=timer++;
    for(int v:graph[curr]){
        if(v!=parent){
            euler_tour(v,curr);
        }
    }
    tout[curr]=timer; //  tin[i]+subtree_size[i]=tout[i]          ; if timer++ -> tin[i]+subtree_size[i] -1=tout[i]
}

// In segment tree or any other data structure, at 0 th index, element with tin[i]=0 comes, at 1-> tin[j]=1 , at pos 2-> k such that tin[k]=3, and so on
// if we use timer++ above, then we have to change implementation of data structure and query accordingly.


// Here I will demonstrate using BIT
Incomplete ->














// video explanation -> https://www.youtube.com/watch?v=MOy4UDjN8DM  (from 25 to 30)


// differnt approach explanation -> https://codeforces.com/blog/entry/102087













int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	return 0;
}