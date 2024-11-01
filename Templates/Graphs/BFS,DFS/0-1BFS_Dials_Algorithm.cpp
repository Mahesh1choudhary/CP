#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

vector<vector<pair<int,int>>> graph;// (v,weight)

//O(m)
// Algo- smaller weight(=0 or equivalent to zero) add in front, larger weights(=1 or equivalent to 1) add in back of queue
vector<int> BFS01(int i){
    vector<int> d(graph.size(),1e9);
    d[i]=0;
    deque<int> q;
    q.push_front(i);
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for( auto edge:graph[u]){
            int v=edge.first, w=edge.second
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                if(w==0){
                    q.push_front(v);
                }
                else{
                    q.push_back(v);
                }
            }
        }
    }
    return d;
}



// Link ->  https://codeforces.com/blog/entry/88408
// O(n*k + m)
// if every edge has weight<=k-1 (k different weights including 0), then we can use k buckets
//If every edge in the graph has a weight <= k-1 , then the distances of vertices in the queue will differ by at most k-1  from the distance of previous vertice from the source and connected to this vertex through edge. So we can keep k buckets.
vector<int> dials_algo(int i){
    vector<int> d(graph.size(),1e9);
    vector<int> used(graph.size(),false);
    vector<queue<int>> q(k);
    d[i]=0;
    q[0].push(i);
    int pos=0; // index of current queue in q vector
    int num=1; // total vertices present in q;
    while(num>0){
        while(q[pos].empty()){  // min distance vertex is always in current queue or in next queue 
            pos=(pos+1)%k;      // as when an edge is added its distance is always greater than current vertex
        }
        int u=q[pos].front();
        q[pos].pop();
        num--;
        if(used[u]) continue; // used vertex can be in other queues

        used[u]=true;
        for(auto edge:graph[u]){
            int v= edge.first, w=edge.second;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q[d[v]%k].push(v);
                num++;
            }
        }
    }

    return d;
}

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	return 0;
}












// GOOD QUESTIONS 
// Q1 - https://codeforces.com/problemset/problem/821/D