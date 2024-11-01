#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// DSU with path compression alone gives O(logn), and similarly with union by size alone will give O(logn) complexity

struct union_find{
    vector<int> id,sz;
    union_find(int n){
        id=vector<int>(n);
        sz=vector<int>(n);
        for(int i=0;i<n;i++){
            id[i]=i, sz[i]=1;    
        }
    }
    int root(int i){
        while(i!=id[i]){
            id[i]=id[id[i]];
            i=id[i];
        }
        return i;
    }

    bool connected(int x, int y){
        return root(x)==root(y);
    }

    void dounion(int x,int y){
        int a=root(x), b=root(y);
        if(a==b){
            return;
        }
        if(sz[a]<sz[b]){
            id[a]=b;
            sz[b]+=sz[a];
        }
        else{
            id[b]=a;
            sz[a]+=sz[b];
        }
    }
};
// WE CAN EASILY STORE ADDITIONAL INFORMATION FOR EACH SET, BY STORING IT AT THE CURRENT REPRESENTATIVE NODES.


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    
	return 0;
}