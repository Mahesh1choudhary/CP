
// LINK 1 -> https://cp-algorithms.com/graph/bridge-searching.html
// LINK 2- DFS Tree -> https://codeforces.com/blog/entry/68138

// BRIDGES EXITS IN UNDIRECTED GRAPHS

// from link 1
int n;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> tin,low;
vector<pair<int,int>> bridges;
int timer=0;
void dfs(int v, int parent=-1){
    visited[v]=true;
    tin[v]=low[v]=timer++;
    for(int to:graph[v]){
        if(to==p) continue;
        if(visited[to]){
            low[v]=min(low[v],tin[to]);
        }
        else{
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>tin[v]){
                bridges.push_back({v,to});
            }
        }
    }
}


void find_bridges(){
    timer=0;
    visited.assgin(n,false);
    tin.assign(n,-1);
    low.assign(n,-1);
    for(int i=0;i<n;i++){
        if(!visited[i]) dfs(i);
    }
}


