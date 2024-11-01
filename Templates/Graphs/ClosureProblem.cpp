#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

INCOMPLETE

// Directed graph with vertices have weights, find maximum or minimum weight closure
// Closure- Set of vertices C, such that no edge leave C

//Minimum weight closure- complement of maximum weight closure in complement of graph

// Algorithm - First replace given graph with its condensation graph
// add two additional vertices s and t
// connects edges between s to positive weight vertices v with capacity same as weight, and between t to negative weight vertices with capacity = - weights
// make capacity of all other edges= infinite
// minimum cut willr be the solution


struct EdmondKarp{
    // Edmonds-Karp implementation of Ford-Fulkerson algorithm which finds shortest path between s ant t in terms of number of edges
    int INF=1e9;
    vector<vector<int>> graph; //adjacency list representation
    vector<vector<int>> capacity; // matrix representation
    vector<int> parent; // parent[i]= parent of vertec i in path; used in bfs function
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

}



int main(){

    

    return 0;
}