#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;
int INF=1e9;
vector<vector<int>> graph; //adjacency list representation
vector<vector<int>> capacity,cost; // matrix representation
//here cost is per unit flow cost
int n; // no of vertices in graph
vector<int> parent;
vector<int> dist; // shortest distance to each vertex from s

// using dijkstra, finding shortest from s to every other vertex
void shortestpath(int s){
    fill(dist.begin(),dist.end(),INF);
    fill(parent.begin(),parent.end(),-1);
    dist[s]=0;
    vector<bool> marked(n,false);
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        marked[u]=false;
        for(int v:graph[u]){
            if(capacity[u][v] && dist[v]>dist[u]+cost[u][v]){
                dist[v]=dist[u]+cost[u][v];
                parent[v]=u;
                if(!marked[v]){
                    marked[v]=true;
                    q.push(v);
                }
            }
        }
    }

}
// min cost of flow of size k from s to t
int mincostflow(int k, int s, int t){
    int flow=0,mincost=0;
    while(flow<k){
        shortestpath(s);
        if(dist[t]==INF){
            break;
        }
        int f=k-flow;
        int cur=t;
        while(cur!=s){
            f=min(f,capacity[parent[cur]][cur]);
            cur=parent[cur];
        }
        
        flow+=f;
        mincost+=f*dist[t];
        cur=t;
        while(cur!=s){
            capacity[parent[cur]][cur]-=f;
            capacity[cur][parent[cur]]+=f;
            cur=parent[cur];
        }
    }
    if(flow<k){
        return -1; // flow of size k doses not exits
    }
    else{
        return mincost;
    }

}




int main(){

    

    return 0;
}