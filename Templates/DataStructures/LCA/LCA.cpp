#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// First Method ->  each query in O(logn) with O(n) preprocessing
// LCA(v1,v2)  can be uniquely determined by finding the vertex with the smallest height in the Euler tour between first(v1) and first(v2);
//  to find minimum height element between first(v1) amd first(v2), we use segment tree- O(logn) per query, sparse table- O(1) per query, but other data structures can also be used

struct LCA {
    vector<int> height, euler , first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root=0){
        n=adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(2*n);
        visited.assign(n,false);
        dfs(adj,root);
        int m=euler.size();
        segtree.resize(4*m);
        build(1,0,m-1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h=0){
        visited[node]=true;
        height[node]=h;
        first[node]=euler.size();
        euler.push_back(node);
        for(auto to:adj[node]){
            if(!visited[to]){
                dfs(adj,to,h+1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int tl,int tr){
        if(tl==tr){
            segtree[tl]=euler[tl];
        }
        else{
            int mid= (tl+tr)/2;
            build(2*node, tl, mid);
            build(2*node+1, mid+1, tr);
            int left=segtree[2*node] , right=segtree[2*node+1];
            segtree[node]=(height[left]<height[right])?left:right;
        }
    }

    int query(int node, int tl, int tr, int l, int r){
        if(l>r){
            return -1;
        }
        
        if(l==tl && r==tr){
            return segtree[node];
        }
        int tm=(tl+tr)/2;
        int left= query(2*node,tl,tm,l,min(r,tm));
        int right= query(2*node+1, tm+1, tr, max(l,tm+1),r);
        
        if(left==-1) return right;
        else if(right==-1) return left;
        else{
            return height[left]<height[right]?left:right;
        }

    }
    int lca(int u, int v){
        int left=first[u], right=first[v];
        if(left>right){
            swap(left,right);
        }
        return query(1,0,euler.size()-1, left, right);
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    
	return 0;
}