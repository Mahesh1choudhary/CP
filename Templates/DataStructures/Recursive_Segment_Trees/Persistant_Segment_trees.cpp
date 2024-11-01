#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


// LINK 1 - https://discuss.codechef.com/t/persistence-made-simple-tutorial/14915
// LINK 2 - https://cp-algorithms.com/data_structures/segment_tree.html#preserving-the-history-of-its-values-persistent-segment-tree
// LINK 3 - https://codeforces.com/blog/entry/15890

// we can either do pinter pased or vector based- just like trie implemnetation
// Here we will do pointer implementation of range sum and point update- Implementation from LINK2
// change it to smart pointer based implementation to prevent memory leaks 

// POINTER-BASED IMPLEMENTATION
vector<int> a;
struct vertex{
    vertex *left, *right;
    int sum;

    vertex(int val):left(nullptr), right(nullptr), sum(val){}
    vertex(vertex *l , vertex *r): left(l), right(r), sum(0){
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
};

vertex* build(int tl, int tr){
    if(tl==tr){
        return new vertex(a[tl]);
    }
    int mid=(tl+tr)/2;
    return new vertex(build(tl,mid), build(mid+1,tr));
}

int query(vertex *v, int tl, int tr, int l, int r){
    if(l>r) return 0;
    if(tl==l && tr==r) return v->sum;
    int mid=(tl+tr)/2;
    return query(v->left, tl,mid,l,min(mid,r)) + query(v->right,mid+1,tr,max(l,mid+1),r);
}

vertex* update(vertex *v, int tl, int tr, int ind, int val){
    if(tl==tr) return new vertex(val);
    int mid=(tl+tr)/2;
    if(ind<=mid) return new vertex(update(v->left, tl,mid,ind,val), v->right);
    else return new vertex(v->left, update(v->right,mid+1,tr,ind,val));
}

void erase(vertex *v, int tl, int tr){
    if(tl==tr){
        delete v;
        return;
    }
    int mid=(tl+tr)/2;
    erase(v->left, tl,mid);
    erase(v->right, mid+1,tr);
    delete v;
}

// for checking value of each version, we have to store root of each update


// smart pointer based implementation
vector<int> a;
struct vertex{
    unique_ptr<vertex> l, r;
    int sum;

    vertex(int val):l(nullptr), r(nullptr), sum(val){}
    vertex(unique_ptr<vertex> l , unique_ptr<vertex> r): l(move(l)), r(move(r)), sum(0){
        if(this->l) sum += this->l->sum;
        if(this->r) sum += this->r->sum;
    }
};

unique_ptr<vertex> build(int tl, int tr){
    if(tl==tr){
        return make_unique<vertex>(a[tl]);
    }
    int mid=(tl+tr)/2;
    return make_unique<vertex>(build(tl,mid), build(mid+1,tr));
}

int query(const unique_ptr<vertex>& v, int tl, int tr, int l, int r){
    if(l>r) return 0;
    if(tl==l && tr==r) return v->sum;
    int mid=(tl+tr)/2;
    return query(v->l, tl,mid,l,min(mid,r)) + query(v->r,mid+1,tr,max(l,mid+1),r);
}

unique_ptr<vertex> update(const unique_ptr<vertex>& v, int tl, int tr, int ind, int val){
    if(tl==tr) return make_unique<vertex>(val);
    int mid=(tl+tr)/2;
    if(ind<=mid) return make_unique<vertex>(update(v->l, tl,mid,ind,val), make_unique<vertex>(*v->r));
    else return make_unique<vertex>(make_unique<vertex>(*v->l), update(v->r,mid+1,tr,ind,val));
}




// VECTOR BASED IMPLEMNETATION



