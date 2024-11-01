#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// Link - https://cp-algorithms.com/graph/mst_prim.html

// startng from any one vertex, add edge with the minimum weight that has one end in an already selected vertex (i.e. a vertex that is already part of the spanning tree), and the other end in an unselected vertex
// repeat the process until the dpanning tree has n-1 edges



// For dense graph - O(n^2) time compexity
// We approach this problem from a different angle: for every not yet selected vertex we will store the minimum edge to an already selected vertex.
// Then during a step we only have to look at these minimum weight edges, which will have a complexity of O(n)
// After adding an edge some minimum edge pointers have to be recalculated. Note that the weights only can decrease, i.e. the minimal weight edge of every not yet selected vertex might stay the same,
//  or it will be updated by an edge to the newly selected vertex. Therefore this phase can also be done in  O(n).


int n;
vector<vector<int>> graph;  // adjacency matrix of graph, INF if there is no edge between i and j
int INF=1000000000;

struct Edge{
    int w=INF, to=-1;
}

void prim(){
    int total_weight=0;
    vector<bool> visited(n,false);  // selected vertices
    vector<Edge> min_edge(n);   // keeps minimum weight edge for non selected vertex to selected vertex
    min_edge[0].w=0;

    for(int i=0;i<n;i++){
        int v=-1;
        for(int j=0;j<n;j++){
            if(!visited[j] && (v==-1 || min_edge[j].w<min_edge[v].w)){
                v=j;
            }
        }

        if(min_edge[v].w==INF){
            cout<<"No MST"<<endl;
            return;
        }

        visited[v]=true;
        total_weight+=min_edge[v].w;
        if(min_edge[v].to!=-1){
            cout<<v<<" "<<min_edge[v].to<<endl;
        }

        for(int to=0;to<n;to++){
            if(graph[v][to]<min_edge[to].w){
                min_edge[to]={graph[v][to],v};
            }
        }

    }

    cout<<total_weight<<endl;
}





// sparse graph - O(mlogn)
// The main algorithm remains the same, but now we can find the minimum edge in O(logn) time.
// On the other hand recomputing the pointers will now take O(nlogn), which is worse than in the previous algorithm

struct Edge{
    int w=INF, to=-1;
    bool operator <(Edge &other){
        return make_pair(w,to)<make_pair(other.w, other.to);
    }
}

// Incomplete
int n;
vector<vector<Edge>> graph;










