#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// Link - https://codeforces.com/topic/76681/en17
// Link2 - https://codeforces.com/blog/entry/124286

//  when we want to find some value or DPv for every vertex in a tree,then rerooting can be used to move the
// root from a vertex to one of its adjacent vertices in O(1)

// when changing root r to one of its adjacent vertices v, then only DPr and DPv can change, so that we can 
// update DPr using its new children and last DPr, also Dpv can be updated the same way

void move(int oldroot, int newroot){
    // Update data structures as if `new_root` was being removed as a child from `old_root`
    // Update data structures as if `old_root` was being added as a child to `new_root`
}

void dfs(int curr, int parent){
    int valcurr=dp[curr];
    int valv;
    for(int v: tree[curr]){ // childrens of current vertex
        if(v==parent){
            continue;
        }
        valv=dp[v];
        int valvcurr=dp[curr];
        
        move(v,curr); // function to move root from curr vertex to v vertex in O(1)
        
        dfs(v,curr);

        //moving root back to curr and updating dp, overall moving to initial condition
        dp[v]=valv;    // for these two lines we can also use move(v,curr)
        dp[curr]=valcurr;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    calculateDP(rat); // function to calculate dp when root is rat
	dfs(rat,rat); // function to move root to all the vertices;
	
	return 0;
}