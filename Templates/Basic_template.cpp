#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define For(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back;
#define LL long long

using namespace std;



// to reduce collisions(thus lesser time consumption) and to avoid hacking
/*struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//unordered_map<long long, int, custom_hash> safe_map;
//safe_map.reserve((1<<20));
//safe_map.max_load_factor(0.25);

//unordered_set<long long,custom_hash> safe_set
//safe_set.resize((1<<20));
//safe_set.max_load_factor(0.25);
*/














int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	return 0;
}