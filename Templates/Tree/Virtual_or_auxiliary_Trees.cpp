#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// LINK -> https://www.youtube.com/watch?v=czySm7bUHgY,         https://discuss.codechef.com/t/icl1705-editorial/14269

/* Question -> We have a tree with n vertices and q queries, in each query, we are given ki verties, we need to find 
sum of distance all ki*(ki+1)/2 pairs of vertices
Generally other questions solvable using virtual tree are of this pattern, some vertices for each query are given and we have to find something on this vertices

also k1+k2+....kq = s
Basic appraoch- we can use one of method 1 or 2 as per requeirements
1. -> for each query, do sinple dfs + dp, i.e. contribution of each edge -> O(N) for each query          -> overall O(q*N)
2. -> For each query, find value using LCA and computing distance -> O(k*k), with LCA in O(1)           -> overall O(k1*k1 + k2*k2....+kq*kq)

3. -> If k1+k2+....kq=s, then there are root(s) distinct values of ki, atmost root(s) values will be greater than root(s) and at most root(s) values will be lesser than root(s)
Using combination of above two appraoch, if k is lesser than root(s), use method 2, otherwise use method 1
So overall time complexity -> O(s*root(s)+n*root(s)) which is same as O(s*root(s))

*/

/*
SOLVING USING VIRTUAL TREES
ALGORITHM
 1. Sort the vertices v[1].... v[k] by their DFS order;  (here v[1]...v[k] are the vertices on which we have to answer queries), total vertices in tree are n                => O(k*logk)
 2. Add LCA(v[i],v[i+1]) to the list of vertices for all 1<=i<k   , here also keep given k vertices as virtual tree also contains them                               => O(k*logn) using binary lifting -> almost same as (k*logk)
 3. Again sort by DFS order and also remove duplicates -> O(k*logk)
 
 4. Maintain a stack like vector such that initially it will contain only the topmost vertex  ( the one with smallest DFS time)             
 5. Go through all vertices in order of their DFS time and change this stack, and add edges accordingly ( the new tree connected may be disconnected or may have many components)          => O(k)
 while creating the virtual tree  we can also add extra informations as per the questions, like making edges weighted with distance between nodes, etc.

 6. Now we have a new tree (weighted/unweighted as per question) with O(k) vertices
 7. Solve the query in linear/ sublinear time

Total time complexity for single query => O(klogk)

Total time complexity for q queries => k1*log(k1) + k2*log(k2)+.....kq*log(kq)
=> s*log(s), where s= k1+k2+....kq

*/ 
// WE CAN USE EXTRA PARAMETERS AS PER THE REQUIREMENT OF THE QUESTION 

#define MAXN 100000
vector<int> tree[MAXN]; // undirected edge
 
// calculate entry and exit_time times of vertices in dfs order, and also precalculating LCAs
int enter_time[MAXN], exit_time[MAXN], depth[MAXN], dfs_time;
int lca[MAXN][20];  // as n<=1e5
void dfs(int u, int par){

    lca[u][0]=par;      // when calling dfs from i, call dfs(i,i), so that lca property is maintained, and be careful or change this condition as required
    for(int i=1;i<20;i++){
        lca[u][i]=lca[lca[u][i-1]][i-1];
    }


    enter_time[u]=++dfs_time;
    for(int v:tree[u]){
        if(v!=par){
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    }
    exit_time[u]=dfs_time;
}

// check if u is above v in tree, i.e. if u is one of the ancestor of v or not
bool is_ancestor(int u, int v){
    return enter_time[u]<=enter_time[v] && exit_time[u]>=exit_time[v];
}

// function to fid lca of two vertices
int find_lca(int u, int v){
    if(is_ancestor(u,v)){
        return u;
    }
    else if(is_ancestor(v,u)){
        return v;
    }
    int curr=v;
    for(int l=19;l>=0;l--){
        if(!is_ancestor(lca[curr][l],u)){
            curr=lca[curr][l];
        }
    }
    return lca[curr][0];
}

void precompute(int root){
    depth[root]=0;
    dfs(root,root);   // assuming tree is 1 indexed

}


// needed for sorting k vertices in dfs order (ordered by enter_timeing time)
bool cmpr(int u, int v){
    return enter_time[u]<enter_time[v];
}

vector<int> virtual_tree[MAXN]; // virtual tree

// to create vertual tree of given vertices
// virtual tree will contain atmost 2*k-1 vertices
int create_virtual_tree(vector<int> &ver){

    sort(ver.begin(), ver.end(),cmpr);

    int k=ver.size();

    // finding lca of all consecutive pairs     =>  O(k)
    for(int i=0;i<k-1;i++){
        int new_vertex=find_lca(ver[i],ver[i+1]);
        ver.push_back(new_vertex);

    }

    // O(k*logk)
    // sorting by dfs order and removing duplicates
    sort(ver.begin(),ver.end(), cmpr); 
    ver.erase(unique(ver.begin(),ver.end()));

    // empting previously build virtual tree(if build)
    for(int v:ver){
        virtual_tree[v].clear();
    }


    vector<int> stck;
    stck.push_back(ver[0]);
    for(int i=1;i<ver.size();i++){
        int u=ver[i];
        while(stck.size()>=2 && !is_ancestor(stck.back(),u)){
            // adding edge
            virtual_tree[stck[stck.size()-2]].push_back(stck.back());
            stck.pop_back();
        }
        stck.push_back(u);
    }


    while(stck.size()>=2){
        // adding edges
        virtual_tree[stck[stck.size()-2]].push_back(stck.back());
        stck.pop_back();
    }

    // if stck contains only one element, then it is the topmost vertex
    // return root of virtual tree;
    return stck[0];
}

bool important[MAXN];   // vertices that are given in query
int subtree_count[MAXN]; // no of vertices in current subtree which are important
int total_count=0;  // total no of important vertices

long long answer_query(int u, int par=-1){
    long long ans=0;

    subtree_count[u]=important[u];
    for(int v:virtual_tree[u]){
        // since virtual tree is directed, we did not need to check if v=par
        ans+=answer_query(v,u);
        subtree_count[u]+=subtree_count[v];
    }

    if(par!=-1){
        int w=depth[u]-depth[par];
        ans+=w*1ll*subtree_count[u]*1ll*(total_count-subtree_count[u]);
    }
    return ans;
}

void solve(){
    int n,q,u,v,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    precompute(1);
    
    cin>>q;
    for(int i=0;i<q;i++){

        // clear everything done for previous query
        for(int v:ver){
            important[v]=false;
            virtual_tree[v].clear();
        }
        ver.clear();


        cin>>k;
        vector<int> ver;
        int x;
        for(int j=0;j<k;j++){
            cin>>x;
            important[x]=true;
            ver.push_back(x);
        }

        total_count=ver.size();

        int vt_root = create_virtual_tree(ver); // root of virtual tree

        cout<<answer_query(vt_root)<<endl;

        // reseting global array important to answer next queries
        for(int x:ver){
            important[x]=false;
        }
    }

}







