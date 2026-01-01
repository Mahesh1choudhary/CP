#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// DSU with path compression alone gives O(logn), and similarly with union by size alone will give O(logn) complexity


// WE CAN EASILY STORE ADDITIONAL INFORMATION FOR EACH SET, BY STORING IT AT THE CURRENT REPRESENTATIVE NODES.



struct union_find{
    vector<int> id, sz;
    union_find(int n){
        id= vector<int>(n);
        sz= vector<int>(n);
        for(int i=0;i<n;i++) id[i]=i, sz[i]=1;
    }
    
    
    int root(int i){
        while(id[i]!=i){
            id[i]= id[id[i]];
            i=id[i];
        }
        return i;
    }
    
    bool is_connected(int i, int j){
        return root(i) == root(j);
    }
    
    void do_union(int i, int j){
        i=root(i), j=root(j);
        if(i==j) return;
        if(sz[i] > sz[j]){
            id[j]= i;
            sz[i] += sz[j];
        }
        else{
            id[i]= j;
            sz[j] +=sz[i];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    
	return 0;
}