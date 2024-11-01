#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// For directed graph
// Condensation graph ->  graph containing every strongly connected component as one vertex. Each vertex of the condensation graph corresponds to the strongly connected component of graph  
// The most important property of the condensation graph is that it is acyclic.

// Kosaraju Sharir algorithm 
// Find reverse topological sort
// Build Transposed graph
// Run dfs on transposed graph in reverse topological order
// O(n+m);

vector<vector<int>> graph, tgraph;  // graph and transposed graph
vector<int> toposort;
vector<bool> visited;
vector<int> component; // vertices in current component for some processing

void dfs1(int i){
    visited[i]=true;
    for(int v:graph[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    toposort.pb(i);
}


void dfs2(int i){
    visited[i]=true;
    component.push_back(i);
    for(int v:tgraph[i]){
        if(!visited[v]){
            dfs2(v);
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    // assuming vertices are 1-indexed
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    reverse(toposort.begin(),toposort.end());
    visited.assign(n+1,false);

    int cnt=0; // no of components
    for(int v:toposort){
        if(!visited[v]){
            cnt++;
            dfs2(v);
            // processing this component;
            component.clear();
        }
    }
	
	
	return 0;
}







