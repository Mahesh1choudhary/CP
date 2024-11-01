#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

// Link - https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html

// For all Pair shortest path For both directed and undirected graphs
// works also for negative weights as long as there are no negative weight cycyles.

// This algorithm can also be used to detect negative cycles. The graph has a negative cycle if at the end of the algorithm, the distance from a vertex v to itself is negative.


// Before k-th phase (k = 1...n), d[i][j]  for any vertices i and j stores the length of the shortest path between the vertex i and vertex j, which contains only the vertices  
// {1, 2, ..., k-1}  as internal vertices in the path.


// O(n^3)

vector<vector<int>> dist;   // dist[i][j]= shortest distance between vertex i and j
// initially d[i][j]=wij, if there is edge between i and j, INF otherwise

// if vertex no starts from1 instead of 0, then start i,j,k from i till n
void Floyd_warshall(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]<INF && dist[k][j]<INF){   // check is necessary if there are negative edges
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}



// If we also need to find path
vector<vector<int>> p;  // p[i][j]= element that is present between i and j, if i and j are directly connected , then put i, also p[i][i]=-1;

void Floyd_warshall(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]<INF && dist[k][j]<INF){   // check is necessary if there are negative edges
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]= dist[i][k]+dist[k][j];
                        p[i][j]=k;
                    }
                }
            }
        }
    }
}

// may not be correct
vector<int> path;
path.pb(i);
void find_path(int i, int j){
    if(p[i][j]==i){
        return;
    }
    find_path(i,p[i][j]);
    path.pb(p[i][j]);
    find_path(p[i][j],j);
}
path.pb(j);







// Finding negative cycles- First run normal floyd-warshall with dist[v][v]=0, if there is negative length path from v to v , then d[v][v] will be smaller than 0
// We can use above resuts to find all pairs of vetices that don't have a shortest path between them.
// iterate over all (i,j) and for each pair we check whether they have a shortest path between them. To do this, we try all possibilities for and intermediate vertex t.
// (i,j) doesn't have a shortest path, if one of the intermediate vertices t has dist[t][t]<0, t can be reached from i and j can be reached from t.
void Floyd_warshall(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]<INF && dist[k][j]<INF){   // check is necessary if there are negative edges
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    if(dist[k][k]<0){
                        dist[i][j]=-INF;
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int t=0;t<n;t++){
                if(dist[i][j]<INF && dist[t][j]<INF && dist[t][t]<0){
                    dist[i][j]=-INF;
                }
            }
        }
    }



}











