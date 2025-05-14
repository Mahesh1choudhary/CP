#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// LINK1 - https://cp-algorithms.com/data_structures/segment_tree.html#dynamic-segment-tree

// LINK2 - https://codeforces.com/blog/entry/60837

// LINK3 - https://codeforces.com/blog/entry/19080?#comment-239925


/* MAIN IDEA - SAY WE HAVE UNDERLYING ARRAY WITH 1E9 POSSIBLE LOCATIONS, BUT ONLY CONTAINED 1E5 ELEMENTS.
OBVIOUSLY, WE CAN'T STORE ALL 1E9 ELEMENTS IN SEGTREE
THERE ARE TWO SOLUTION TO THIS PROBLEM-
    1- BY COMPRESSING ALL POSSIBLE VALUES TO LOWER NUMBER USING HASH_MAP OR RESIZING, BUT THIS IS NOT VERY EFFICIENT IN TIME
    ALSO THIS APPRAOCH OF USING HASHING CAN'T BE USED IF TASK IS INTERACTIVE THAT IS WHEN ONLINE SOLUTION IS REQUIRED -> SEE THIS -> https://codeforces.com/blog/entry/19080?#comment-239928

    2- USING DYNAMIC SEGMENT TREE- ITS ALWAYS BETTER THAN APPRAOCH ONE(EITHER RECURSIVE OR ITERATIVE)
    ALSO WE CAN'T IMPLEMENT DYNAMIC SEGMENT TREE AND PERSISITENT SEGMENT TREE USING ITERATIVE APPRAOCH. BUT WITH POLICY HASH TABLE, WE CAN IMPLEMENT DYNAMIC SEGMENT TREE in iterative appraoch, BUT ITS PERFORMANCE IS RELATIVELY SLOWER THAN RECURSIVE DYNAMICS SEGMENT TREE
    SEE LINK2
*/



// MAIN IDEA OF DYNAMIC SEGMENT TREE -> WE CREATE A NODE ONLY WHEN WE NEED IT
// SO, WE WILL USE POINTER BASED IMPLEMENTATION





// Here is implementation for (similar to LINK3+LINK1)-> range query- sum in range, point query- adding a value to a position
// This idea can be extended in lots of different ways- range update, range query, lazy propagation,etc

struct node{
    int tl,tr; // range covered by vertex
    int sum=0;  // value stored at the vertex
    node *left_child=nullptr, *right_child=nullptr;   // pointers to left ans right child

    node(int lb, int rb){
        tl=lb;
        tr=rb;
    }

    void extend(){
        if(!left_child && tl+1<=tr){
            int mid=(tl+tr)/2;
            left_child=new node(tl,mid);
            right_child= new node(mid+1,tr);
        }
    }

    int getSum(int l, int r){
        if(l>r){
            return 0;
        }
        if(l==tl && r==tr){
            return sum;
        }
        
        if(!left_child) return 0;
        // adding this one line will reduce memory usage a lot- check submissions of Q1
        // as if we do not use this line, we will create unnecessary nodes.


        int mid=(tl+tr)/2;
        return left_child->getSum(l,min(mid,r)) + right_child->getSum(max(mid+1,l),r);

    }

    void update(int pos, int newVal){
        if(tl==tr){
            sum+=newVal;
            return;
        }

        extend();
        int mid=(tl+tr)/2;
        if(pos<=mid) left_child->update(pos,newVal);
        else right_child->update(pos,newVal);
        sum=left_child->sum + right_child->sum;
    }


    void delete_node(){
        if(left_child){
            left_child->delete_node();
            right_child->delete_node();
            delete left_child;
            delete right_child;
            left_child=nullptr;
            right_child=nullptr;
        }
    }
}


// Check implementation of Q1 to know how to create nodes and call functions




// VERY GOOD QUESTIONS
// Q1 - https://codeforces.com/problemset/problem/762/E





