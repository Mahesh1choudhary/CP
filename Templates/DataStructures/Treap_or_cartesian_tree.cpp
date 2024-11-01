#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// Treap -> Binary Serch Tree + heap   -> https://cp-algorithms.com/data_structures/treap.html#implementation
// https://codeforces.com/blog/entry/112664
// https://codeforces.com/blog/entry/92340,   





// here we will create max heap, but we can also create minheap in the same way

struct item{
    int key, priority;
    item *l, *r;    // pointer to left and right subtree
    item(){}
    item(int key): key(key), priority(rand()), l(NULL), r(NULL){};
    item(int key, int priority): key(key), priority(priority), l(NULL), r(NULL){}

}

typedef item* pitem;

// spliting treap trp by value k into two treaps and storing left trip in lft and right treap in rht
// O(logn)
void split(pitem trp, int k, pitem & lft, pitem & rht){
    // if current node is NULL or current treap is null, then l and r will be null
    if(!trp){
        lft=rht=NULL;
    }
    // if key of current node is <= given key
    // then left tree will contain complete left part + some right paret, right tree will contain remaining right part
    // store new left part in trp->r and right part in rht, here new means of the newtreap which is trp->r
    else if(trp->key <=k){
        split(trp->r, k, trp->r, rht);
        lft=trp;
    }
    else{
        split(trp->l, k, lft, trp->l);
        rht=trp;
    }
}
//  Note that we do not return the result values anywhere



// inserting item it in treap trp
// O(logn)
void insert(pitem & trp, pitem it){
    // if current node or item is null, then assign item it to it
    if(!trp){
        trp=it;
    }
    // if priority of new item is high, then it becam root, then split trp into lft subtree= keys <= key of it, and rht with keys > it-> key;
    else if(it->priority > trp->priority){
        split(trp, it->key, it->l, it->r);
         trp=it;
    }
    // otherwise root of trp remains same, compare children's keys or  move to childrens to check
    else{
        // if key of root <= key of item it, then move to right subtree else to left subtree to insert
        insert(trp->key <= it->key ? trp->r : trp->l , it);
    }
}

// merge(T1, T2) -> It works under the assumption that  T1  and  T2  are ordered (all keys  X in  T1  are smaller than keys in  T2 ).
// we choose as the root the tree which has higher priority in the root node, and recursively call Merge for the other tree and the corresponding subtree of the selected root node.
// merge treaps lft and rht and retuen their root as trp
// O(logn)
void merge(pitem & trp, pitem lft, pitem rht){
    // if lft is null make rht as current node or item and vice verse, if both are null do nothing
    if(!lft || !rht){
        trp=lft ? lft : rht;
    }
    // if below condition is true, then root of lft will be the root of final treap
    else if(lft->priority > rht->priority){
        merge(lft->r, lft->r , r);
        trp=l;
    }
    else{
        merge(rht->l, lft, rht->l);
        trp=r;
    }
}


// erase node or item with key value= k, if there are multiple elements with key k, then call erase multiple times
// O(logn)
void erase( pitem & trp, int k){
    if(trp->key == k){
        pitem ti=trp;
        merge(trp, trp->l, trp->r);
        delete ti;  // deleting ti node to free memory
    }
    else{
        erase(k < trp->key ? trp->l : trp->r, k);
    }
}


//
pitem unite(pitem lft, pitem rht){


}













/* GOOD QUESTIONS
Q1  - https://codeforces.com/contest/1988/problem/E
*/