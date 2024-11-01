#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;



// LINK - https://cp-algorithms.com/string/rabin-karp.html
// Cheking occurences of s in t in O(|s| + |t|);
// Algorithm -> compute hash of s, compute hash of each prefix of t and compare each substring of length |s| with s

vector<int> Rabin_Karp(string s, string t){
    const int p=31;
    const int m=1e9+9;
    int sl=s.size(), tl=t.size();

    vector<long long> p_pow(max(sl,tl));
    p_pow[0]=1;
    for(int i=1;i<(int)p_pow.size();i++){
        p_pow[i]=(p_pow[i-1]*p)%m;
    }

    vector<long long> pre_hash(tl+1,0); // we start from pre_hash[1], so that we don't have to consider cases like i>0 or i==0
    for(int i=0;i<tl;i++){
        pre_hash[i+1]=(pre_hash[i]+(t[i]-'a'+1)*p_pow[i])%m;
    }

    long long hash_s=0;
    for(int i=0;i<sl;i++){
        hash_s=(hash_s+ (s[i]-'a'+1)*p_pow[i])%m;
    }

    vector<int> occurrences;
    for(int i=0;i<i+sl-1<tl;i++){
        long long cur_hash=(pre_hash[i+sl]-pre_hash[i]+m)%m;
        if(cur_hash==hash_s*p_pow[i]%m){
            occurrences.push_back(i);
        }
    }
    return occurrences;

}











