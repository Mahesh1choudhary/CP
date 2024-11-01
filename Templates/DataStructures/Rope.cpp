#include <iostream>
#include <bits/stdc++.h>
#include <ext/rope> /// header with rope
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;
using namespace __gnu_cxx;  /// namespace with rope and some additional stuff


// Link -> https://codeforces.com/blog/entry/10355

// rope data structure in STL can fastly insert arbitrary blocks of array to any position
// and erase them. So it's very similar to implicit cartesian tree, but 2 times slower
// than the handwritten implicit cartesian tree, but uses less memory






int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    rope<int> v;
    for(int i=0;i<1e5;i++) v.push_back(i);

    // we can do operation like below in O(logn) in worst case( adding or removing only one element);
    for(int i=0;i<1e5;i++){
        cin>>l>>r;
        l--,r--;
        rope<int> cur=v.substr(l,r-l+1);
        v.erase(l,r-l+1);
        v.insert(v.mutable_begin(),cur);
    }
    
	return 0;
}

// From SGI STL's documentation it's known that the rope doesn't cope well with
//  modifications of single elements (that's why begin() and end() return const_iterator. 
// If you want to use classic iterators, you should call mutable_begin() and mutable_end().)

