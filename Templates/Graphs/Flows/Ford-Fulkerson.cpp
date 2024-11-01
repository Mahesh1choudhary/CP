#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// Using DFS for Ford-Fulkerson algorithm which finds any path between s ant t
// using either dfs gives O(mF) complexity for interger flows , where F is maximum possible flow , but if flows are not intergers, then it is not bounded


int INF=1e9;
vector<vector<int>> graph; //adjacency list representation
vector<vector<int>> capacity; // matrix representation
vector<int> parent; // parent[i]= parent of vertec i in path; used in dfs function
// gives flow increase in path from s to t in one round
int dfs(int s, int t){
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    stack<pair<int,int>> stk;
    stk.push({s,INF});
    while(!stk.empty()){
        int cur=stk.top().first;
        int flow= stk.top().second;
        stk.pop();
        for(int next:graph[cur]){
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next]=cur;
                int newflow=min(flow,capacity[cur][next]);
                if(next==t){
                    return newflow;
                }
                stk.push({next,newflow});
            }
        }
    }
    return 0;
}

int maxflow(int s,int t){
    int flow=0;
    int newflow=0;
    while(newflow=dfs(s,t)){
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


int main(){

    

    return 0;
}