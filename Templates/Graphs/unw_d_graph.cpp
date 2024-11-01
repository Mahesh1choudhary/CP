#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;
int INF=1e9;
// for unweighted directed graph
class directed_graph{
    public:
    vector<vector<pair<int,int>>> gr; //adjacency list representation- vertex starts from 1, 0 is not a vertex
    vector<int> used; // used[i]=true, if vertex i is visited in some algorithm
    

    directed_graph(int n){
        gr=vector<vector<int>>(n+1); // as first vertex is 1
        used=vector<int>(n+1);
    }

    // bfs-O(n+m), n= vertices, m=edges
    vector<int> bfs(int i){
        vector<int> d(gr.size(),INF);
        queue<int> q;
        q.push(i);
        d[i]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:gr[u]){
                if(d[u]+1<=d[v]){
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d;
    }

    // O(n+m);
    bool dfs(int i){
        stack<int> st;
        st.insert(i);
        used[i]=1;
        while(!st.empty()){
            int u=st.top();
            st.pop();
            for(int v:gr[u]){
                if(used[v]==0){
                    st.insert(v);
                    used[v]=1;
                }
                else if(used[v]==1){
                    return true;
                }
            }
            used[u]=2;
        }
        return false;
    }

    // O(n+m);
    void is_cycle(int i){
        fill(used.begin(),used.end(),0);
        for(int i=1;i<=gr.size();i++){
            if(used[i]==0 && dfs(i)){
                return true;
            }
        }
        return false;
    }
    vector<int> topoans; // topological s
    void dfs2(int i){
        for(int a:gr[i]){
            if(!used[a]){
                used[a]=true;
                dfs2(a);
            }
        }
        topoans.emplace_back(i);
    }
    
    // if cycle exits than no topological sorting is possible
    // topological sort- vertex first in order has edges to vertices next in order but to vertex before in order 
    vector<int> topo_sort(){
        fill(used.begin(),used.end(),0);
        topoans.clear();
        for(int i=1;i<=gr.size();i++){
            if(!used[i]){
                used[i]=true;
                dfs2(i);
            }
        }
        reverse(topoans.begin(),topoans.end());
        return topoans;
        
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	return 0;
}