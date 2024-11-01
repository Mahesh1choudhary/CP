#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;









// iterative DFS
vector<bool> visited;
vector<vector<int>> graph;
void dfs(int i){
    stack<int> st;
    st.push(i);
    while(st.size()>0){
        int u=st.top();
        st.pop();
        if(!visited[u]){
            visited[u]=true;
            for(int v:graph[u]){
                if(!visited[v]){
                    st.push(v);
                }
            }
        }
    }
}