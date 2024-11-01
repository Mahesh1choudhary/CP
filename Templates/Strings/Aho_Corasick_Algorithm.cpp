#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;


// LINK -> https://cp-algorithms.com/string/aho_corasick.html

// Invariant -> current state is the longest partial match in the processed string. 
// suffix link for vertex p is an edge that point to the longest proper suffix of the string corresponding to the vertex p.
// exception is root -> its suffix link point to itself

/* For constructing automaton, for each vertex in increasing order of distance from root -> while there is no transition from the current vertex of the trie using the current letter (or until we reach the root), we follow suffix link.

The suffix links of the root vertex and all its immediate children point to the root vertex. For any vertex v deeper in the tree, we can calculate the suffix link as follows: if p is the ancestor of v with c being the letter labeling the edge from p to v, 
go to p, then follow its suffix link, and perform the transition with the letter c from there.
*/

// When there is only one string in trie, then Aho-Corasick is actually KMP
// The basic structure is trie- we add extra suffix links in it



int k= 26;  // possible number of characters in the string
struct vertex{
    vector<int> next;   // inices of next vertex with given character
    bool found=false    // true if a string ends at this vertex
    int p =-1;          // parent vertex of current vertex
    char pch;           // character with which current vertex comes from parent vertex ->  p to pch gives current vertex
    int link = 0;      // suffix link (0(root is link) if it has not been calculated yet)
    vector<int> go;     // transitions in the machine for each character ( -1 if it has not been calculated yet)
    int next_terminal

    vertex(int p=-1, char ch='$'){
        next=vector<int>(k,-1);
        go=vector<int>(k,-1);
        this.p=p, this.ch=ch;
    }
}

struct AhoCorasick{
    vector<vertex> trie;
    AhoCorasick(){
        // index 0 is the root
        trie=vector<vertex>(1);
    }

    void add_string(string s){
        int v=0;
        for(char ch:s){
            int c=ch-'a';
            if(trie[v].next[c]==-1){
                trie[v].next[c]=trie.size();
                trie.emplace_back(v,ch);
            }
            v=trie[v].next[c];
        }
        trie[v].found=true;
    }
    // incomplete- not fully understood
    // look at these -> https://codeforces.com/blog/entry/14854,  and cp algorithms
    void push_links(){
        queue<int> q;
        q.push(0);
        while(!q.empty){
            int v=q.front();
            auto cur=trie[v];   // current vertex
            auto link=trie[cur.link];   // link vertex ofcurrent vertex
            q.pop();
            cur.next_terminal = link.terminal?cur.link:link.next_terminal;

            for(int c=0;c<k;c++){
                if(cur.next[c]>0){
                    trie[cur.next[c]].link=v?lin.next[c]:0;
                    q.push(cur.next[c]);
                }
                else{
                    cur.next[c]=link.next[c];
                }
            }
        }
    }

}













