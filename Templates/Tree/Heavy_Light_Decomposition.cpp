#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// HLD is used for answering path queries on tree
// LINK -> https://codeforces.com/blog/entry/81317
//        https://codeforces.com/blog/entry/104997t
// In some cases Trick 1 from tricks.cpp can be used to answer path queries on tree


// Below we are assuming tree to be 0-indexed and considers 0 as the root. Also if tree root is not given, then we can make any node as root if question permits

struct HLD{
    vector<int> sz; // to store size of each subtree
    vector<int> parent; // to store parent of each vertex
    vector<int> bigchild;   // to store the biggest child at each vertex
    vector<int> depth;  // to store depth of each vertex
    
    int label_time=0;   // number to be given to current vertex
    vector<int> label; // labeling of nodes-> this labeling is only used in segment tree, not anywhere else. At all other cases, the normal labeling or given labeling of nodes is used
    vector<int> chain;  // head of the chain to which current vertex belong in a heavy chain
    // initially set all chain[i]=i in the main function

    int lg ;    // value of log2(n)+1
    vector<vector<int>> lca_lift;    // to store the lifted parent - Binary lifting for finding LCA


    vector<int> segtr;

    /*
    CREATE SEGMENT TREE ON HEAVY NODES WHICH ARE DENOTED BY NEW LABEL AS PER THE QUESTION REQUIREMENT

    Below implementation is to find the xor of vertices on path between u to v
    For different questions , mostly segment tree implementation changes
    */

    void build(){

    }


    void update(){

    }


    void query(){
        
    }
    









    /* =>  compute size of each subtree and take child with maximum size , in case of ties, break by choosing any.
    Also set depth of each vertex relative to root which is used for later evaluating queries
    */
    void dfs(int v, int p, int d){
        sz[v]=1;
        depth[v]=d;
        parent[v]=p;

        int bigc=-1,bigv=-1;    // biggest vertex , size of its subtree

        for(int x:edges[v]){
            if(x!=p){
                dfs(x,v,d+1);
                sz[v]+=sz[x];
                if(sz[x]>bigv){
                    bigc=x;
                    bigv=sz[x];
                }
            }
        }
        bigchild[v]=bigc; 
    }


    /*
    labeling nodes
    label the nodes so that heavy chains end up together in the labeling-> for this , we do a dfs and label nodes by visiting bigger child before everything else
    In this way, the labels on heavy chains form consecutive sequences of numbers, so they can be easily queries with the segment tree.

    In this block, we will also FIND HEAVY CHAINS. For each vertex, compute the vertex at the top of the heavy chain it belongs to (which could be itself)
    */
    //  NEW LABELING IS USED ONLY FOR CREATING SEGMENT TREE, NOT ANYWHERE ELSE. AT ALL OTHER CASES, INITIAL LABELING IS USED
    
    void dfs_labels(int v, int p){
        label[v]=label_time++;

        seg_update()    // put values in segtr appropriately

        if(bigchild[v]!=-1){
            chain[bigchild[v]]=chain[v];
            dfs_labels(bigchild[v],v);
        }
        for(int x:edges[v]){
            if(x!=p && x!=bigchild[v]){
                dfs_labels(x,v);
            }
        }
    }


    /*
    Doing binary lifting for finding lowest common ancestors needed for answering queries
    */
    
    void lca_dfs(int v, int p){
        lca[v][0]=p;

        // in main function, for root vertex, make lca[root][i]=root for all i , so that no error occurs here
        for(int i=1;i<lg;i++){
            lca[v][i]=lca[lca[v][i-1]][i-1];
        }

        for(int x:edges[v]){
            if(x!=p){
                lca_dfs(x,v);
            }
        }
    }


    int lca(int u, int v){
        
    }




    // finding the answer for a chain from p to v , where p is some ancestor of v
    // Below is for xor query, change this as per question
    long long query_chain(int v, int p){
        long long val=0;
        while(depht[p]<depth[v]){
            int top=chain[v];
            if(depht[top]<=depth[p]){
                int diff=depth[v]-depth[p];
                top=get_kth_ancestor(v,diff-1);
            }
            val= val^seg_query(label[top],lavel[v]);
            v=parent[top];
        }
    }


    // finding path query betweeen u to v= from u to lca(u,v)(excluding) + from v to lca(u,v)(excluding) + lca(u,v)
    long long query(int u, int v){
        int lc= lca(u,v);
        long long val = query_chain(u,lc)^query_chain(v,lc)^seg_query(label[lc],label[lc]);
        return val;

    }




    void heavy_light(vector<vector<int>> &tree){
        int n=tree.size();
        int lg=log2(n)+1;
        parent=vector<int>(n);
        depth=vector<int>(n);
        sz=vector<int>(n);
        bigchild=vector<int>(n);
        labels=vector<int>(n);
        chain=vector<int>(n);
        lca=vector<vector<int>>(n,vector<int>(lg));


        for(int i=0;i<n;i++) chain[i]=i;


        
    }


}










