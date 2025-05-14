#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// Link -> https://cp-algorithms.com/data_structures/segment_tree.html#addition-on-segments
// storing dp in segment tree question -> https://codeforces.com/problemset/problem/1814/E

/*
arithmetic progression in segment tree
LINK2 ->  https://stackoverflow.com/questions/39929725/update-in-segment-tree
LINK3 -> https://codeforces.com/blog/entry/64521

two ways to handle using lazy propagation-> {starting element, ending element} or {starting element, difference}

// check once, used {start element, ending element}
const int maxn=2e5+5;
int segtr[4*maxn]; pair<int,int> add[4*maxn];

void build(int v, int tl, int tr){
    if(tl==tr){
        segtr[v]=0, add[v]={0,0};
        return;
    }
    int mid=(tl+tr)/2;
    build(2*v,tl,mid), build(2*v+1,mid+1,tr);
    segtr[v]=0, add[v]={0,0};
}

void push(int v,tl,tr){
    int mid=(tl+tr)/2;
    add[2*v].first+=add[v].first, add[2*v].second+= add[v].first+ mid-tl;
    add[2*v+1].first+= add[v].second -(tr-mid-1), add[2*v+1].second+=add[v].second;
    add[v]={0,0};
}
void update(int v, int tl, int tr, int l, r,int vall, valr){
    if(l>r) return;
    
    if(tl==l && tr==r){
        add[v].first+=vall;
        add[v].second+=valr;
        return;
    }
    push(v,tl,tr);
    int mid=(tl+tr)/2;
    update(2*v,tl,mid,l,min(mid,r),vall, vall+min(mid,r)-l);
    update(2*v+1,mid+1,tr,max(mid+1,l),r, valr-r+max(mid+1,l),valr);
    
    segtr[v]=max(segtr[2*v], segtr[2*v+1]);
}
*/

int n, segt[4*MAXN];


// we need to store at most 4*n vertices. It might be less, but for convenience we always allocate an array of size 4*n; 
// There will be some elements in the sum array, that will not correspond to any vertices in the actual tree, 
// but this doesn't complicate the implementation.


// preprocessing in O(n) assuming merge/combining is O(1);
// array a is 0-indexed, but t is 1-indexed, v-current vertex, tl left boundary of current segment
// tr- right boundary of current segment.

/// O(n*f), f= complexity of merge
void build(int a[], int v, int tl, int tr){
    if(tl==tr){
        segt[v]=a[tl]; // for sum queries, can change as per required function
    }
    else{
        int tm=(tl+tr)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        segt[v]=segt[2*v]+segt[2*v+1]; // for sum queries, can change as per required function
    }
}

// segment tree is kept 1 indexed, so that 2*v and 2*v+1 gives children vertices of v and v/2 gives parent
// in main program call build(a,1,0,n-1) to build the segment tree;


// range query in O(logn)- assuming O(1) for combining, otherwise O(f*logn), f=complexity of mergin or combining
// v- current vertex, tl- left boundary of current vertex, tr- right boundary of current vertex
// l- left boundary(some index in array a) of query, r- right boundary of query 
int query(int v, int tl, int tr, int l, int r){
    if(l>r){
        return 0; // can change as per required function -> if we have problem in what to return in such case then we can use alternative approach by considering cases separately -> whether l>=tl and r<=tr, and other cases, etc
    }
    if(l==tl && r==tr){
        return segt[v];
    }
    int tm=(tl+tr)/2;
    return query(2*v,tl,tm,l,min(r,tm))+query(2*v+1, tm+1, tr, max(l,tm+1),r); // for sum query, can change as per required function
}
// query(1,0,n-1,l,r);

// point update in O(logn), assuming O(1) for combining, otherwise O(f*logn), f=complexity of merging or combining
// pos- position of element(in array a-0-indexed) to be updated, new_val- new value to be put
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl==tr){
        segt[v]=new_val;
    }
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm){
            update(2*v,tl,tm,pos,new_val);
        }
        else{
            update(2*v+1,tm+1,tr,pos,new_val);
        }
        segt[v]=segt[2*v]+segt[2*v+1]; // for sum update, can change as per required function.
    }
}


//Different combining function for different types of queries
// combining should be done in a separate function, since this will be required in building tree, answering queries and in updating

// finding maximum and number of times it apperas.
// we store {max, count of max} at each vertex of segt
pair<int,int> combine(pair<int,int> x, pair<int,int> y){
    if(x.first>y.first) return x;
    if(x.first<y.first) return y;
    return make_pair(x.first,x.second+y.second);
}
// here combine is also O(1) 




// computing gcd or similarly lcm
int combine(int x, int y){
    if(y>x) swap(x,y);
    while(y>0){
        x%=y;
        swap(x,y);
    }
    return x;
}
// here combine is O(log(min(x,y)));
// so build is O(n*A)), query is O(logn * A), update is O(logn * A);
// where A= maximum value of log(min(x,y)) occured during build/update/query
















///// STORING ENTIRE SUBARRAYS IN EACH INDEX
/* if no updates are needed, then we can define segt as vector<vector<int>> and do similar approach for building 
 and answering queries. building in O(nlogn), memory is also O(nlogn)
*/
// Example question -> Find the smallest number greater oe rqual to a specified number- without modification queries

vector<vector<int>> segtr(4*Max_N, vector<int>());
vector<int> a;
void build(int v, int tl, int tr){
    if(tl==tr) segtr[v].pb(a[tl]);
    else{
        int tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1, tm+1, tr);
        merge(segtr[2*v].begin(), segtr[2*v].end(), segtr[2*v+1].begin(), segtr[2*v+1].end(), back_inserter(segtr[v]));

    }
}

// answering query -> using binary search, we find element >= than given element in current vertex
// Time conplexity O((logn)^2)

int query(int v, int tl, int tr, int l ,int r, int x){
    if(l>r){
        return INF; // INF -> number bigger than all elements of array
    }
    if(l==tl && r==tr){
        auto index=lower_bound(segtr[v].begin(), segtr[v].end(),x);
        if(index!=segtr[v].end()){
            return *index;
        }
        return INF; // If no element is >=x, then return INF
    }
    int tm=(tl+tr)/2;
    return min(query(2*v, tl, tm, l, min(r,tm), x),  query(2*v+1, tm+1, tr, max(l, tm+1), r, x));
}





/*But also need to update values (point updates in array), then define segt as vector<multiset<int>> , as multiset allows to search for
 numbers, delete numbers, and insert new numbers.
*/
 //construction can be done in O(n(logn)^2);

vector<multiset<int>> segtr(4*Max_N, multiset<int>());
vector<int> a;
void build(int v, int tl, int tr){
    if(tl==tr) segtr[v].insert(a[tl]);
    else{
        int tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1, tm+1, tr);
        merge(segtr[2*v].begin(), segtr[2*v].end(), segtr[2*v+1].begin(), segtr[2*v+1].end(), back_inserter(segtr[v]));

    }
}

void query(int v, int tl, int tr, int l, int r, int x){
    if(l>r){
        return INF;
    }
    if(l==tl && r==tr){
        auto index=segtr[v].lower_bound(x);
        if(index!=segtr[v].end()){
            return *index;
        }
        return INF;
    }
    int tm=(tl+tr)/2;
    return min(query(2*v, tl, tm, l, min(r,tm), x),  query(2*v+1, tm+1, tr, max(l, tm+1), r, x));

}


 
/*
 For updating , we go down the tree and modify all multiset from the corresponding segments that contain effected element, we simply delete
 old value of this element and insert new value.
 So in O((logn)^2);
*/
/////

 void update(int v, int tl, int tr, int pos, int new_val) {
    segtr[v].erase(t[v].find(a[pos]));
    segtr[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
    } else {
        a[pos] = new_val;
    }
}

//  LATER STUDY FRACTIONAL CASCADING






//// RANGE UPDATES
// Example question -> add a number  x  to all numbers in the segment  
// a[l .... r] . The second query, that we are supposed to answer, asked simply for the value of  a[i] .

vector<int> a;
vector<int> segtr(4*MAX_N);
void build(int v, int tl, int tr) {
    if (tl == tr) {
        segtr[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        segtr[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        segtr[v] += x;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return segtr[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return segtr[v] + get(v*2, tl, tm, pos);
    else
        return segtr[v] + get(v*2+1, tm+1, tr, pos);
}




// RANGE UPDATES - LAZY PROPAGATION
// Example question -> assign each element of a certain segment  a[l .... r]  to some value  p . As a second query we will again consider reading the value of the array  a[i] .

// To perform this modification query on a whole segment, you have to store at each vertex of the Segment Tree whether the corresponding segment is covered entirely with the same value or not.

// push -> function will receive the current vertex, and it will push the information for its vertex to both its children
// We will call this function at the beginning of the query functions(updating and reading both) (but we will not call it from the leaves, because there is no need to push information from them any further).

vector<bool> marked(4*MAX_N);
vector<int> segtr(4*MAX_N);

void push(int v){
    if(marked[v]){
        segtr[2*v]=segtr[v];
        segtr[2*v+1]=segtr[v];
        marked[2*v]=true;
        marked[2*v+1]=true;
        marked[v]=false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val){
    if(l>r) return;
    if(tl==l && tr==r){
        segtr[v]=new_val;
        marked[v]=true;
    }
    else{
        push(v);
        int tm=(tl+tr)/2;
        update(2*v, tl,tm, l,min(tm,r), new_val);
        update(2*v+1, tm+1, tr, max(tm+1, l), r, new_val);
    }

}


int get(int v, int tl, int tr, int pos){
    if(tl==tr){
        return segtree[v];
    }
    push(v);
    int tm=(tl+tr)/2;
    if(pos>=tm){
        return get(2*v, tl, tm, pos);
    }
    else{
        return get(2*v+1, tm+1, tr, pos);
    }
}



// If we have to do range updates and then query( lets say min element or max elements ), then we need to maintain two segment trees -
// one segment tree to store min element , and other to store lazy updates

int segtr[4000000], extra[4000000];


void build(int v, int tl, int tr){
    if(tl==tr){
        segtr[v]=a[tl];
        return;
    }
    int mid=(tl+tr)/2;
    build(2*v,tl,mid), build(2*v+1,mid_1,tr);
    segtr[v]=min(segtr[2*v],segtr[2*v+1]);
}

// to add values stored at vertex v to its children accordingly
void push(){
    extra[2*v]+=extra[v];
    extra[2*v+1]+=extra[v];
    extra[v]=0;
}

// add or subtract val from [l,r]
void update(int v, int tl, int tr, int l, int r, int val){
    if(l>r) return;
    if(tl==l && tr==r){
        extra[v]+=val;
        return;
    }
    push(v);
    int mid=(tl+tr)/2;
    update(2*v,tl,mid,l,min(mid,tr),val), update(2*v+1,mid+1,tr,max(mid+1,l),r,val);
    segtr[v]=min(segtr[2*v]+extra[2*v],segtr[2*v+1]+extra[2*v+1]);
}

// minimum element in range [l,r]
int query(int v, int tl, int tr, int l, int r){
    if(l>r) return INF;
    if(tl==l && tr==r){
        return segtr[v]+extra[v];
        return;
    }
    push(v);
    int mid=(tl+tr)/2;
    query(2*v,tl,mid,l,min(mid,r)), query(2*v+1,mid+1,tr,max(l,mid+1),r);
}




































// We can change segment tree as per the required question
/* Best Questions 
 1- https://codeforces.com/problemset/problem/899/F   - changing meaning of segment tree as per need
 2- https://codeforces.com/problemset/problem/817/F         - lazy segment tree with double push

*/





