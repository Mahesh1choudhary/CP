#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// LINK -> https://cp-algorithms.com/graph/pruefer_code.html

// prufer code/sequence -> way of encoding a labeled tree into a sequence of numbers in a unique way
// incoding a labeled tree with n vertices using a sequence of n-2 integers in interval [0,n-1].

// Algorithm -> select leaf with smallest number, remove it from the tree, and write down the number of vertex that was connected to it, Repaet it for n-2 times which leaves only 2 nodes


// Here we are assuming that label is same as the node number, nodes are numbered from 0 to n-1
//METHOD 1 ->  O(nlogn) -> maintain a data structure(set/priority queue) to find the minimum leaf
vector<vector<int>> tree;
vector<int> prufer_code(){
    int n=tree.size();
    set<int> leaf_vals;
    vector<int> degree(n);
    vector<bool> killed(n,false);
    
    for(int i=0;i<n;i++){
        degree[i]=tree[i].size();
        if(degree[i]==1){
            leaf_vals.insert(i);
        }
    }

    vector<int> code(n-2);
    for(int i=0;i<n-2;i++){
        int leaf=*leaf_vals.begin();
        leaf_vals.erase(leaf);
        killed[leaf]=true;

        int v;
        for(int u:tree[leaf]){
            if(!killed[u]){
                v=u;
            }
        }

        code[i]=v;
        if(--degree[v]==1){
            leaf_vals.insert(v);
        }
    }
    return code;
}




// METHOD 2 -> O(n) approach

vector<vector<int>> adj;
vector<int> parent;

void dfs(int v) {
    for (int u : adj[v]) {
        if (u != parent[v]) {
            parent[u] = v;
            dfs(u);
        }
    }
}

vector<int> pruefer_code() {
    int n = adj.size();
    parent.resize(n);
    parent[n-1] = -1;
    dfs(n-1);

    int ptr = -1;
    vector<int> degree(n);
    for (int i=0;i<n;i++) {
        degree[i]=adj[i].size();
        if(degree[i]==1 && ptr==-1)
            ptr=i;
    }

    vector<int> code(n-2);
    int leaf=ptr;
    for(int i=0;i<n-2;i++) {
        int next=parent[leaf];
        code[i]=next;
        if(--degree[next]==1 && next<ptr) {
            leaf=next;
        }else{
            ptr++;
            while(degree[ptr]!=1)
                ptr++;
            leaf=ptr;
        }
    }

    return code;
}





// RESTORING TREE FROM PRUFER CODE

// Property -> Each vertex appears in the Prüfer code exactly a fixed number of times - its degree minus one.
// METHOD 1 -> O(nlogn) -> using above property, we can get degree of each vertex and leaf vertices, and first removed will be the smallest of all leaves, and continue in this way
// Algorithm -> look for minimum vertex with degree 1, connect it with the next vertex from the prufer code and reduce the degree.
// In the end we only have two vertices left with degree equal to 1 .These are the vertices that didn't got removed by the Prüfer code process. We connect them to get the last edge of the tree.

vector<pair<int,int>> prufer_decode(vector<int> &code){
    int n=code.size()+2;
    vector<int> degree(n,1);
    for(int i:code){
        degree[i]++;
    }

    set<int> leaves;
    for(int i=0;i<n;i++){
        if(degree[i]==1) leaves.insert(i);
    }

    vector<pair<int,int>> edges;
    for(int v:code){
        int leaf=*leaves.begin();
        leaves.erase(leaf);

        edges.emplace_back(leaf,v);
        if(--degree[v]==1) leaves.insert(v);
    }
    edges.emplace_back(*leaves.begin(), n-1);
    return edges;
}



// METHOD 2 -> in O(n)
vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
    int n=code.size() + 2;
    vector<int> degree(n,1);
    for (int i:code)
        degree[i]++;

    int ptr=0;
    while (degree[ptr]!=1)
        ptr++;
    int leaf=ptr;

    vector<pair<int,int>> edges;
    for(int v:code) {
        edges.emplace_back(leaf,v);
        if (--degree[v]==1 && v<ptr) {
            leaf=v;
        } else {
            ptr++;
            while(degree[ptr]!=1)
                ptr++;
            leaf=ptr;
        }
    }
    edges.emplace_back(leaf, n-1);
    return edges;
}






