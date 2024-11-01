#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


// Link -> https://cp-algorithms.com/graph/bellman_ford.html
// FOr directed graphs   ( not for undirected graphs)
// Bellmand Ford- For single source shortest paths
// works also on negative weights as long as there are no negative cycles

// The algorithm consists of several phases. Each phase scans through all edges of the graph, and the algorithm tries to produce relaxation along each edge 
// n-1 phases of the algorithm are sufficient to correctly calculate the lengths of all shortest paths in the graph


//Unlike many other graph algorithms, for Bellman-Ford algorithm, it is more convenient to represent the graph using a single list of all edges (instead of  
// n  lists of edges - edges from each vertex)
// O(nm)
struct Edge{
    int u, v, w;
}

// time complexity - O(n*m)
vector<Edge> edges;
vector<int> dist, parent;
void Bellmans_Ford(int s){
    dist.assign(n,INF);
    parent.assign(n,-1);
    dist[s]=0;
    // doing atmost n-1 iterations
    for(int i=1;i<=n-1;i++){
        bool any_update=false;
        for(Edge e:edges){  // u-->v with weight w
            if(dist[e.u]<INF){  // this check is needed if graph  contains negative weight edges
            //no such verification would result in relaxation from the vertices to which paths have not yet found, and incorrect distance, of the type  INF-1,  INF-2  etc. would appear.
                if(dist[e.v]> dist[e.u]+e.w){
                    dist[e.v]=dist[e.u]+w;
                    parent[e.v]=e.u;
                    any_update=true;
                }
            }
        }
        if(!any_update){
            break;
        }
    }


}

// ====> After the execution of  i th  phase, the Bellman-Ford algorithm correctly finds all shortest paths whose number of edges does not exceed  i







// To check presence of negative cycle, run for one extra loop, if any updates happens, then there is a negative cycle, and the node where
// update happens is a part of negative cycle.

// finding negative weight cycle reacheable from s
void Bellmans_Ford(int s){
    dist.assign(n,INF);
    parent.assign(n,-1);
    dist[s]=0;
    int x;
    for(int i=1;i<=n;i++){
        x=-1;
        for(Edge e:edges){  // u-->v with weight w
            if(dist[e.u]<INF){  // this check is needed if graph  contains negative weight edges
                if(dist[e.v]> dist[e.u]+e.w){
                    dist[e.v]=max(-INF,dist[e.u]+w); // Due to the presence of a negative cycle, for n iterations of the algorithm, the distances may go far in the negative range
                    parent[e.v]=e.u;
                    x=e.v;
                }
            }
        }
    }

    // vertex x will either lie in a negative weight cycle, or is reachable from it. To get the vertices that are guaranteed to lie in a negative cycle, starting from the vertex  
    // x, pass through to the predecessors  n  times. Hence we will get the vertex  y , namely the vertex in the cycle earliest reachable from source. We have to go from this vertex, through the predecessors, until we get back to the same vertex  
    if(x==-1){
        cout<<"NO negative weight cycle"<<endl;
    }
    else{
        int y=x;
        for(int i=0;i<n;i++){
            y=parent[y];
        }

        vector<int> path;
        for(int cur=y;;cur=parent[cur]){
            path.push_back(cur);
            if(cur==y && path.size()>1){
                break;
            }
        }
        reverse(path.begin(), path.end());

    }

}

// The above implementation looks for a negative cycle reachable from some starting vertex s.
// however, the algorithm can be modified to just looking for any negative cycle in the graph. For this we need to put all the distance to and not infinity
