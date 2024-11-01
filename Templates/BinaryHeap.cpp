#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

struct minHeap{
    vector<int> v;   // 1-indexed
    int n;  // elements in heap

    minHeap(int l){
        n=0;
        v=vector<int>(l); // l=maximum possible size of vector v
        v.push_back(0); // because v is 1-indexed
    }


    // k is index of element to move up
    void swim(int k){
        while(k>1 && v[k/2]>v[k]){
            swap(v[k],v[k/2]);
            k/=2;
        }
    }

    void insert(int x){
        v.pb(x);
        n++;
        swim(n);
    }

    // k is index of element to sink or whose value is decreased
    void sink(int k){
        while(2*k<=n){
            int j=2*k;
            if(j<n && v[j]>v[j+1]){
                j++;
            }
            if(v[k]<v[j]){
                break;
            }
            else{
                swap(v[k],v[j]);
            }
            k=j;
        }
    }

    int delmin(){
        int ans=v[1];
        swap(v[1],v[n]);
        n--;
        sink(1);
        v[n+1]=0;
        return ans;
    }

    bool isempty(){
        return n==0;
    }

    // update value of key with index k with val
    void decreasekey(int k, int val){
        v[k]=val;
        swim(k);
    }

    void increasekey(int k, int val){
        v[k]=val;
        sink(k);
    }

    // if key w is present or not, if present return its index
    int contains(int w){
        for(int i=1;i<=n;i++){
            if(v[i]==w){
                return i;
            }
        }
        return -1;
    }



};



