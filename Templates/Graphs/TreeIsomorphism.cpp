#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;
INCOMPLETE
int INF=1e9;

struct Tree{
    int n;
    vector<vector<int>> g;
    Tree(){}
    Tree(int _n):n(_n){
        g.resize(n+1); // g[0] has no significance, 1-n are vertices or nodes
    }

    void add_edge(int u,int v){
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> bfs(int s){
        queue<int> q;
        vector<int> d(n+1,n*2); // 2*n large value which is always greater than max possible distance between two nodes
        d[0]=-1;
        q.push(s);
        d[s]=0;
        while(!q,empty()){
            int u=q.front();
            q.pop();
            for(auto v:g[u]){
                if(d[u]+1<d[v]){
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d;
    }

    vector<int> get_centers(){
        auto du=bfs(1);
        int v= max_element(du.begin(),du.end())-du.begin(); //index of max element
        auto dv=bfs(v);
        int u=max_element(dv.begin(),dv.end())-dv.begin();
        du=bfs(u);
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(du[i]+dv[i]==du[v] && du[i]>=du[v]/2 && dv[i]>=du[v]/2){
                ans.pb(i);
            }
        }
        return ans;
    }



}



int main(){

    

    return 0;
}