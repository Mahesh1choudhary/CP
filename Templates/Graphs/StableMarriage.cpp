#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

/*Given n men and n women, where each person has ranked all members of the opposite sex
in order of preference, marry the men and women together such that
there are no two people of opposite sex who would both rather have
each other than their current partners. When there are no such pairs of people,
the set of marriages is deemed stable. There is always a solution
m[][],w[][] lists partners in order of their preferences
it always yields the one that is best for all men among all stable matchings, and worst for all women. complexity O(n^2)*/
// If we start from women , the nwe get best for women but worst for men


INCOMPLETE
int m[N][N], w[N][N], id[N],marry[N],ans[N],pref[N][N];
void StableMatching(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i), id[i]=1;
    }
    memset(marry, -1, sizeof marry);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pref[i][m[i][j]]=j;
        }
    }
    while(!q.empty());

}



int main(){

    

    return 0;
}