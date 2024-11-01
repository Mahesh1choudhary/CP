
// LINK 1 - https://codeforces.com/blog/entry/85714
// LINK 2 - https://mzhang2021.github.io/cp-blog/kruskal/
// LINK 3 - https://codeforces.com/blog/entry/100666

#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// given - (edge weighted or vertex weighted or not weight depends on problem) (connectd or not connected) graph with n vertices and M edges
/* Reacheability tree or DSU tree can help with
    Find the minimal/maximal weight of the edges when traversing from vertex u to vertex v
    Find the set of vertices that are reachable from a given vertex using the first x edges, for some arbitrary x

    You can think of the reachability tree as a DSU but with no path compression, so each subtree of some internal
     node in the reachability tree is the set of vertices in the connected component that contains the associated edge at the point when you were adding it.
*/

/*
To build this tree, we start with the N leaves, then iterate the edges of the graph one by one starting from the smallest one to the largest one. When adding an edge that connects u
 and v, add a new node to the tree, then attach the current root(s) of u and v in the trees as the children of the newly added node. Finding these roots can be done using DSU data structure.

When possible, you may omit the edges that connect two vertices from the same connected component, and the reachability tree you end 
up with will only have 2N−1 nodes.

*/

// DSU tree will have at most 2n-1 vertices

int l; // current no of vertices in tree
vector<vector<int>> graph;
vector<int> dsu;    // size should be atleast vertices +edges
vector<pair<int,int>> edges; // sorted in required order by weight

int root(int u){
    while(u!=dsu[u]){
        u=dsu[u];
    }
    return u;
}

void addedge(int u, int v){
    u=root(u), v=root(v);
    dsu[l]=l;   // as vertices are 0 indexed
    dsu[u]=dsu[v]=l;

    graph[l].pb(u);
    if(u!=v) graph[l].pb(v);
    l++;

}

void build(){
    for(int i=0;i<n;i++) dsu[i]=i;
    for(int i=0;i<m;i++) addedge(edges[i].first, edges[i].second);
    // add edges in the order required for solving problem
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	return 0;
}


