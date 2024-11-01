#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// LINK - https://cp-algorithms.com/string/prefix-function.html
// Prefix function - array pi of length n where pi[i] is the length of the longest proper prefix of the substring  s[0...i] which is also a suffix of substring.
// pi[0]=0;




// string is 0 indexed  ,  O(n)
vector<int> prefix_function(string s){
    int n= (int)s.length();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    return pi;
}
// This is an online algorithm, it processes the data as it arrives.
// The algorithm still requires storing the string itself and the previously calculated values of prefix function, but if we know beforehand the maximum value M the prefix function can take on the string, we can store only  
// M+1  first characters of the string and the same number of values of the prefix function.

/*
if we know that the prefix values never exceed 
a certain value, then we do not need to store the
entire string and also the entire function, but only its beginning.
For example -> i searching for a substring in a string, t+#+s, if |t|=n, then since each value will be <=n, so we need just the previous value and prefix function from 0 to n-1, as previous value will always take the next iteration of while loop into string t
*/





// BUILDING A AUTOMATON ACCORDING TO THE PREFIX FUNCTION
// LINK -> https://cp-algorithms.com/string/prefix-function.html#building-an-automaton-according-to-the-prefix-function

// we can construct an automaton(a finite state machine): the state in it is the current value of the prefix function, and the transition from one state to another will be performed via the next character.

// O(26*n) time complexity, O(26*n) space complexity
void compute_automaton(string s, vector<vector<int>> & aut){
    s+='#'; // set as per the question
    int n=s.size();
    vector<int> pi=prefix_function(s);

    aut.assign(n,vector<int>(26));  // change size as per the number of possible characters.
    // we can understand it as if at position i , we get c, then what is the value of prefix function pi[i]
    for(int i=0;i<n;i++){
        for(int c=0;c<26;c++){
            if(i>0 && 'a'+c!=s[i]){
                aut[i][c]=aut[pi[i-1]][c];
            }
            else{
                aut[i][c]=i+('a'+c==s[i]);
            }
        }
    }
}













int main(){

    

    return 0;
}