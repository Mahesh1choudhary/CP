#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// A tree may have one centroid or may have two centroids. If it has two centroids, they are always connected (otherwise, the tree can't have n vertices).
// we can find these vertices by checking the size of each subtree, doing DFS. When the size of a subtree is s, the size of the other part is n - s.

vector<vector<int>> tr;
vector<int> Centroid(){
    int n=tr.size(); // no of vertices
    vector<int> centroids;
    vector<int> sz(n);
    //  for 1-indexed
    //  int n=tr.size()-1;
    //  vector<int> centroids;
    //  vector<int> sz(n+1);

    function<void (int,int)> dfs = [&](int u, int prev){
        sz[u]=1;
        bool is_centroid=true;
        for(auto v:tr[u]){
            if(v!=prev){
                dfs(v,u);
                sz[u]+=sz[v];
                if(sz[v]>n/2){
                    is_centroid=false;
                }
            }
        }
        if(n-sz[u]>n/2) is_centroid=false;
        if(is_centroid){
            centroids.push_back(u);
        }
    };

    dfs(0,-1); // for 1-indexed dfs(1,-1)
    return centroids;
}








// For diameter

vector<vector<int>> tree;
vector<int> dist;

void bfs(int i){
    queue<int> q;
    q.push(i);
    dist[i]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v:tree[u]){
            if(dist[v]>dist[u]+1){
                q.push(v);
                dist[v]=dist[u]+1;
            }
        }
    }
}
// end points of diameter
pair<int,int> diamter(){
    dist.assign(n+1,1e9);
    bfs(1);
    int strt=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[strt]){
            strt=i;
        }
    }
    dist.assign(n+1,1e9);
    bfs(strt);
    int ed=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[ed]){
            ed=i;
        }
    }
    return make_pair(strt,ed);
}


// centroid of a tree lies in its heaviest child- see Q1



// Centroid related question 
// Q1 - https://codeforces.com/problemset/problem/685/B