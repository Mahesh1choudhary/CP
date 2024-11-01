#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);


    // METHOD 1 -> this mwthod worked only in c++14 and velow versions
    auto dfs=[&](int u,int p,auto&& dfs)->void {
	for(int v:adj[u])
		if(v!=p) {
			//
			dfs(v,u,dfs);
		}
    };

    dfs(0,-1,dfs);





    // METHOD 2 -> works for all versions
    function<void(int, int)> dfs = [&](int u, int p) -> void {
        
        for (int v : adj[u]){
            dfs(v,u);
        }
    };
	
	
	
	return 0;
}