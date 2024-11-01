#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// find all suffices, sort them - we get suffix array, so suffic_arr[i]= starting index of suffix that is at i postion in sorted order


// finding suffix array is equivalent to finding sorting cyclic shifts of string
/* Append an arbitrary character at the end which is smaller than any character of string usually we use $
then order of sorted cyclic shifts is equivalent to order of sorted suffixes.

s[i...j] = substring from i to j if i<=j, otherwise s[i...n-1]+s[0....j]
*/
// O(nlogn) where n is string length


vector<int> suffix_array(string s){
    int n=s.length();
    int alphabet=256;   // possible no of character in string
    vector<int> p(n), c(n), cnt(max(alphabet,n),0);
    // 0 th iteration
    for(int i=0;i<n;i++){
        cnt[s[i]]++;
    }
    for(int i=1;i<alphabet;i++){
        cnt[i]+=cnt[i-1];
    }
    for(int i=0;i<n;i++){
        p[--cnt[s[i]]]=i;
    }
    c[p[0]]=0;
    int classes=1;
    for(int i=1;i<n;i++){
        if(s[p[i]]!=s[p[i-1]]){
            classes++;
        }
        c[p[i]]=classes-1;
    }

    vector<int> pn(n), cn(n);
    // will iterate for ceil(logn) times
    for(int h=0; (1<<h)<n;h++){
        for(int i=0;i<n;i++){
            pn[i]=p[i]-(1<<h);
            if(pn[i]<0) pn[i]+=n;
        }

        fill(cnt.begin(), cnt.end(),0);
        for(int i=0;i<n;i++){
            cnt[c[pn[i]]]++;
        }
        for(int i=1;i<classes;i++){
            cnt[i]+=cnt[i-1];
        }
        for(int i=n-1;i>=0;i--){
            p[--cnt[c[pn[i]]]]=pn[i];
        }
        cn[p[0]]=0;
        classes=1;
        for(int i=1;i<n;i++){
            pair<int<int> cur={c[p[i]], c[(p[i]+(1<<h))%n]};
            pair<int,int> prev={c[p[i-1]], c[(p[i-1]+(1<<h))%n]};
            if(cur!=prev){
                ++classes;
            }
            cn[p[i]]=classes-1;
        }
        c.swap(cn);

    }
    return p;   

}















