#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// Binary lifting concept -> https://cp-algorithms.com/graph/lca_binary_lifting.html
// https://codeforces.com/blog/entry/100826





// O(nlogn) preprocessing and then O(logn) for each query

// Suppose now we received a query (u, v). We can immediately check whether one node
// is the ancestor of the other. In this case this node is already the LCA. If u is not
// the ancestor of v, and v not the ancestor of u, we climb the ancestors of u until we 
// find the highest (i.e. closest to the root) node, which is not an ancestor of v 
// (i.e. a node x, such that x is not an ancestor of v, but up[x][0] is). We can find this node x in  
// O(log N)  time using the array up.


vector<vector<int>> adj;

struct LCA{
    int n,l;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    
    LCA(int root){
        tin.resize(n);
        tout.resize(n);
        timer=0;
        l=ceil(log2(n));
        up.assign(n,vector<int>(l+1));
        dfs(root,root);
    }

    void dfs(int v, int p){
        tin[v]=++timer;
        up[v][0]=p;
        for(int i=1;i<=l;i++){
            up[v][i]=up[up[v][i-1]][i-1];
        }

        for(int u:adj[v]){
            if(u!=p){
                dfs(u,v);
            }
        }
        tout[v]=++timer;
    }

    // if u is ancestor of v;
    bool is_ancestor(int u, int v){
        return tin[u]<=tin[v] && tout[u]>=tout[v];
    }

    int lca(int u, int v){
        if(is_ancestor(u,v)){
            return u;
        }
        if(is_ancestor(v,u)){
            return v;
        }
        for(int i=l;i>=0;i--){
            if(!is_ancestor(up[u][i],v)){
                u=up[u][i];
            }
        }
        return up[u][0];
    }  
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    
	return 0;
}











// GOOD QUESTIONS

//Q1 -  https://codeforces.com/problemset/problem/832/D
// finding common points between two paths u1 to u2, v1 to v2 - check solution and editorial of this question