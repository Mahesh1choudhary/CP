#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;
int INF=1e9;
// for unweighted undirected graph
class undirected_graph{
    public:
    vector<vector<int>> gr; //adjacency list representation- vertex starts from 1, 0 is not a vertex
    int cycle=0; // 1 if cycle is present
    

    //diatance of all vertices from vertex i
    vector<int> bfs(int i){
        
        vector<int> d(graph.size(),INF)
        d[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u=q.front;
            q.pop();
            for(int v:gr[u]){
                if(d[u]+1<d[v]){
                    q.push(v);
                    d[v]=d[u]+1;
                }
                else{
                    cycle=1; // cycle exits
                }
            }
        }
        return d;
    }
    
    
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	return 0;
}