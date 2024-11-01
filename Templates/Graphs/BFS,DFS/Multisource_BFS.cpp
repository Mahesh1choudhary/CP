#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;


// Let there are n nodes and m edges, there are k fire stations , let there is fire at some node x, what
// is the mintime time within which people from one of the fire stations can reach this node x;

// just do bfs with initially all k nodes added into queue;

void bfs( vector<int> knodes){
    queue<int> q;
    for(int k:knodes) q.push(k);
    while(k.size()>0){
        int u=q.front();
        q.pop();
        for(int v:graph[u]){
            if(dist[v]>dist[u]+1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}
