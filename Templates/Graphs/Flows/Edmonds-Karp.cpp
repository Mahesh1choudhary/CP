#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// Edmonds-Karp implementation of Ford-Fulkerson algorithm which finds shortest path between s ant t in terms of number of edges
// O(n*m*m) even for irrational capacities


int INF=1e9;
vector<vector<int>> graph; //adjacency list representation- we convert directed edge into undirected by using reverse edge too
vector<vector<int>> capacity; // matrix representation of residual capacity
vector<int> parent; // parent[i]= parent of vertec i in path; used in bfs function
// The value of the flow in each edge will actually not be stored, but it is easy to extend the implementation - by using an additional matrix - to also store the flow and return it.


// gives flow increase in path from s to t in one round
int bfs(int s, int t){
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,int>> q; // vertex,max flow possible
    q.push({s,INF});

    while(!q.empty()){
        int cur=q.front().first;
        int flow=q.front().second;
        q.pop();

        for(int next:graph[cur]){
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next]=cur;
                int newflow=min(flow,capacity[cur][next]);
                if(next==t){
                    return newflow;
                }
                q.push({next,newflow});
            }
        }
    }
    return 0;

}

int maxflow(int s,int t){
    int flow=0;
    int newflow=0;
    while(newflow=bfs(s,t)){
        flow+=newflow;
        int cur=t;
        while(cur!=s){
            int prev=parent[cur];
            capacity[prev][cur]-=newflow;
            capacity[cur][prev]+=newflow;
            cur=prev;
        }
    }
    return flow;
}




// MINCUT -> one of the mincut can be found out as -> First found maximum flow. Then For mincut, one side includes s and all the vertices reachable from s(using edges with positive residual capacity) in
// the residual graph and other side contains remaining vertices
// we can use dfs for this

vector<int> s_side;

void dfs(int s){
    s_side.push_back(s);
    parent[s]=-2;
    for(int v:graph[s]){
        if(parent[v]==-1 && capacity[s][v]){
            dfs(v);
        }
    }
}


void mincut(int s, int t){
    fill(parent.begin(), parent.end(), -1);
    dfs(s);
    // vertices in other side= vertices that are not in s_side
}





int main(){

    

    return 0;
}