#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;


// Link - https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html

// O(mlogm + n+ m)

struct Edge{
    int from, to,w;
    bool operator< (Edge & other){
        return w<other;
    }
}

vector<Edge> edges;
void kruskal(){
    vector<Edge> result;
    int cost=0;

    sort(edges.begin(), edges.end());
    DSU uf=uf(n);
    for(Edge e:edges){
        if(!uf.connected(e.from, e.to)){
            result.push_back(e);
            cost+=e.w;
            uf.do_union(e.from, e.to);
        }
        //since the MST will contain exactly N-1 edges, we can stop the for loop once we found that many.
        if(result.size()==n-1){
            break;
        }
    }

}



/*

Q1 - https://codeforces.com/problemset/problem/891/C







*/


