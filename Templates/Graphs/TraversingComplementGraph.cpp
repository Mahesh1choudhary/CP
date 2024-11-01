#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

//  https://codeforces.com/blog/entry/93801

// Using DFS in O((n+m)logn), where n= no of vertices, m= no of complement edges(means no edge between u and v);
set<int> unvisited ; /// vertices not visited yet;
vector<set<int>> graph; // adjacency sets of complement edges or complemnet graph in adjacency set format

// if on working on vertex u, if any vertex that is not visited yet and is not in complement set of u, do dfs on it
void dfs(int u){
    unvisited.erase(u);
    if(unvisited.empty()) return;
    auto it=unvisited.begin();
    while(true){
        int v=*it;
        if(graph[u].count(v)==0){
            dfs(v);
        }
        it=unvisited.upper_bound(v);
        if(it==unvisited.end()){
            break;
        }
    }
}
// complexity => at most m skips and at most n dfs, each bounded by logn so O((n+m)logn)





// using BFS in O(m+n);

vector<vector<int>> graph;  // complement graph
vector<int> unvisited(n,0); 
vector<int> unvisited_but_unreachable(n);   // 1- unvisitd and unreacheable from current vertex
vector<int> visited(n,0);   // 1- vertex i is already visited


void bfs(int i){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vector<int> remaining_to_visit;
        
        // blocking all vertices that are not visited yet and are in complement graph not connected with u 
        for(int v:graph[u]){
            // if v is not visited yet but unreacheable from u, block it, no need to worry about visited vertex as they are already processed
            if(!visited[v]){
                remaining_to_visit.pb(v);
                unvisited_but_unreachable[v]=1;
            }
        }
        for(int v:unvisited){
            if(u==v) continue;
            if(unvisited_but_unreachable[v]) continue;
            // do work as per questions and mark this vertex visited
            visited[v]=1;
            q.push(v);
        }

        // clearing the buffer
        for(auto v:remaining_to_visit){
            unvisited_but_unreachable[v]=0;
        }
        // size of remaining to visit is at most deg(u);
        // so complexity remains O(n+m)
        unvisited=move(remaining_to_visit);

    }
}

// Other ideas to traverse complement graph -> https://codeforces.com/blog/entry/79880?#comment-658132,  https://codeforces.com/blog/entry/93801?#comment-1060852



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    
	return 0;
}