#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
// Incomplete


// Link -> https://discuss.codechef.com/t/distinct-numbers-on-an-interval/18350/2
// more description of above case -> https://stackoverflow.com/questions/39787455/is-it-possible-to-query-number-of-distinct-integers-in-a-range-in-olg-n

// we can use policy based data structures -> https://cp-algorithms.com/data_structures/segment_tree.html#find-the-smallest-number-greater-or-equal-to-a-specified-number-no-modification-queries
// but inbuilt merge doesn't work on it, so for now I will use segment tree of vectors and create my own merge function, but in future TRY TO DO WITH POLICY BASED DATA STRUCTRE

// This approach works for Both online and offline queries

// Basic Idea -> 
//create array nxt[] which contains index of next occurence of i,if no occurrence after,then nxt[i]=infinete or some number greater than size of given array
// no of distince elements in [l,r] =>  no.of elements greater than r in range[l,r]
// For handling updates we can simply store the indices of elements in vector.

// if value of elements in given array is <=1e9 something ( then indices size will be very large), even than we can do this as long as long total number of elements <=1e5 or something, we just need to map all elements into a permutaion or simply we can use map

// time complexity O((n+q)logn), space complexity O(nlogn)


// here, we will use segment tree build on array nxt, each node consists of ordered set of the range.So that we can simply binary search and find no.of elements greater than r
vector<int> a;  // given array of elements of size n;
vector<int> nxt; // size same as a
// vector<int> indices;// size = maximum element in the array a, -> if updates are done, then we have to store all occurences so vector<vector<int>>, but here we will use map 
map<int,int> indices
vector<vector<int>> segtree;

// merge vectors at index ind1 and ind2 into at ind3 without duplicates
void merge(int ind1, int ind2, int ind3){
    int i=0, j=0;
    int sz1=segtree[ind1].size(), sz2=segtree[ind2].size();
    int k=0;
    while(true){
        if(i>=sz1 && j>=sz2) break;
        else if(i>=sz1){
            if(k==0 || segtree[ind3][k-1]!=segtree[ind2][j]){
                segtree[ind3].pb(segtree[ind2][j]);
                k++;
            }
            j++;
        }
        else if(j>=sz2){
            if(k==0 || segtree[ind3][k-1]!=segtree[ind1][i]){
                segtree[ind3].pb(segtree[ind1][i]);
                k++;
            }
            i++;
        }
        else{
            if(segtree[ind1][i]<segtree[ind2][j]){
                if(k==0 || segtree[ind3][k-1]!=segtree[ind1][i]){
                    segtree[ind3].pb(segtree[ind1][i]);
                    k++;
                }
                i++;
            }
            else{
                if(k==0 || segtree[ind3][k-1]!=segtree[ind2][j]){
                    segtree[ind3].pb(segtree[ind2][j]);
                    k++;
                }
                j++;
            }
        }
    }
}


void build(int v, int tl, int tr ){
    if(tl==tr){
        segtree[v].pb(nxt[v]);
    }
    else{
        int tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        merge(2*v,2*v+1,v);
    }
}

// finding no of elements greater than val in range l to r (both included)
int query(int v, int tl, int tr, int l, int r, int val){
    if(l>r){
        return 0;
    }
    if(l==tl && r==tr){
        int ind=upper_bound(segtree[v].begin(), segtree[v].end(),val)-segtree[v].begin();
        return (segtree[v].size()-ind);
    }
    int tm=(tl+tr)/2;
    return query(2*v,tl,tm,l,min(r,tm),val)+query(2*v+1, tm+1, tr, max(l,tm+1),r,val);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    // assuming 0-indexed
    for(int i=n-1;i>=0;i--){
        if(indices.count(a[i])==0){
            nxt[i]=n+1; // n+1>n or we can give any value which is >n
            indices[a[i]]=i;
        }
        else{
            nxt[i]=indices[a[i]];
            indices[a[i]]=i;
        }
    }

    build(1,0,n-1);

    for(int i=0;i<q;i++){
        cin>>l>>r;
        l--,r--;
        query(1,0,n-1,l,r,r);
    }


	return 0;
}


// Updates can be handelled with little modifications as given in links












//////// Simple approach for offline queries -> https://www.geeksforgeeks.org/queries-number-distinct-elements-subarray/
