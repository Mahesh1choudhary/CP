#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

int INF=1e9;


// dijkstra works on non-negative weights and on both directed and undirected graphs
// It also works on cycle- as long as it is positive weight cycle


// For dense graph   - O(m+n^2);  
// run n iterations, in each iteration find unvisited vertex with minimum distance and relax edges connected to it. If minimum distance of vertex is INF, then break;
vector<vector<pair<int,int>>> graph;    // to, weight
vector<int> parent, dist; // initialize distance to INF
void dijkstra(int s){
    int n=graph.size();
    dist.assign(n,INF);
    parent.assign(n,-1);
    vector<bool> visited(n,false);

    dist[s]=0;
    for(int i=0;i<n;i++){
        int v=-1;
        // checking all unvisited vertex to find minimum distance vertex
        for(int j=0;j<n;j++){
            if(!visited[j] && (v==-1 || dist[v]>dist[j])){
                v=j;
            }
        }

        if(dist[v]==INF){
            break;
        }

        visited[v]=true;
        for(auto p:graph[v]){
            int to=p.first, w=p.second;
            if(dist[to]>dist[v]+w){
                dist[to]=dist[v]+w;
                parent[to]=v;
            }
        }


    }
}








// For sparse graph - O(mlogn + nlogn)
void dijkstra(int s){
    int n=graph.size();
    dist.assign(n,INF);
    parent.assign(n,-1);
    dist[s]=0;
    set<pair<int,int>> st; // dist[i], i
    st.insert({0,s});

    while(st.size()>0){
        int u=(*st.begin()).second;
        st.erase(st.begin());

        for(auto p:graph[u]){
            int v=p.first, w=p.second;
            if(dist[v]>dist[u]+w){
                st.erase({dist[v],v});
                dist[v]=dist[u]+w;
                st.insert({dist[v],v});
                parent[v]=u;
            }
        }

    }

}
