#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;



// ESSENCE OF BELOW THEORY
// UNORDERED_MAP IS VERY SLOW AS COMPARED TO POLICY HASH_TABLE

//  COMBINING TOPIC1 TO TOPIC2, IN ESSENCE -> 
//define hash function as done in topic 2, then use reserve and load_factor

// For long long, but for int  or pairs see below topics
struct custom_hash {
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

unordered_map<long long, int, custom_hash> safe_map;
safe_map.reserve(1024);
safe_map.max_load_factor(0.25);

unordered_set<long long,custom_hash> safe_set;
safe_set.reserve(1024);
safe_set.max_load_factor(0.25);















/* THEORY -> 1->For making unordered_map/set for custom structs, we need to define hash function.
2-> Even for general variables like int, long long, etc, the inbuilt hash function is not very good and in some cases complexity will blow upto O(n), ande generally unordered_map/set are slow because of large constant factor
3-> We can define our own hash function that almost comletely eliminates collisions and will make sure O(1) complexity. Best hash function are done in Topic 2
4-> There are certain optimisations to unordered_maps with/without custom hash
5-> Using hash_tables from PBDS are best and we also include optimisations in it
*/







// TOPIC 1 -> UNORDERED MAP/SET WITH CUSTOM STRUCTS
// LINK -> https://codeforces.com/blog/entry/21853

// FOR CREATING UNORDERED_MAP FOR CUSTOM STRUCTS, WE JUST NEED TO DEFINE HASH FUNCTION FOR KEY, VALUE CAN BE ANYTHING
//  SIMILARLY FOR SET OF CUSTOM STRUCTS, WE NEED TO DEFINE THE HASH FUNCTION

// for pair<int,int> -> we can use any type of hash function but it should be good and well collision resistent
// also keep in mind the running time of hash function
// USE HASH FUNCTIONS AS DONE IN TOPIC2 , this below one is not very good
struct HASH_function{
    size_t operator()(const pair<int,int> &x)const{
        return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
    }
};

unordered_map<pair<int,int>,int,HASH_function> mp;

set<pair<int,int>, HASH_function> st;


// It seems that sometimes unordered_map becames so slow.but it can improve with this two lines of code
//  THESE ARE VERY GOOD, SO ALWAYS INCLUDE IT
unordered_map<int,int,HASH_function>mp;
mp.reserve(1024);
mp.max_load_factor(0.25);
// With this two lines unordered_map/ set become about 10 times faster.
// You can replace 1024 with another suitable power of two.(it depends on number of inserts you will do).


// reserve ->  When the capacity is not reserved beforehand, it takes capacity as 16 and creates a hashtable on this. 
// Everytime the number of elements increase the threshold, it doubles this capacity and rehashes all the existing keys.
// Reserving an approximate capacity before hand avoids this rehashing and dynamic space allocation, in turn making the program more efficient and reducing the runtime.











// TOPIC 2 -> 
// LINK -> https://codeforces.com/blog/entry/62393
/*
C++ stl implemented unordered map/set have higher changes of collision so chances of O(n) complexity and also can be easily hacked
Use below hash function to avoid being hacked and make sure O(1) complexity
*/

// For long long
struct custom_hash {
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

unordered_map<long long, int, custom_hash> safe_map;

// For pbds hash_table
gp_hash_table<long long, int, custom_hash> safe_hash_table;



// For pair<long long, long long>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<uint64_t,uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM)>>1);
    }
};


// For int -> although we can use function defined as above for long long, but below one is also equivalent
// LINK -> https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key/12996028#12996028
struct custom_hash{
    size_t operator()(int x) const{
        x=(x^(x>>16))*0x45d9f3b;
        x = (x^(x >> 16))*0x45d9f3b;
        x = x^(x >> 16);
        return x;
    }
};










//  COMBINING TOPIC1 TO TOPIC2, IN ESSENCE -> 
//define hash function as done in topic 2, then use reserve and load_factor

struct custom_hash {
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

unordered_map<long long, int, custom_hash> safe_map;
safe_map.reserve(1024);
safe_map.max_load_factor(0.25);


// With this two lines unordered_map/ set become about 10 times faster.
// You can replace 1024 with another suitable power of two.(it depends on number of insert s you will do).








// Method 3 -> using PBDS hash table which are faster as compared to unordered map with optimisation as done above
// LINK -> https://codeforces.com/blog/entry/60737
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

gp_hash_table<int,int> table;
// generally adding resize and load factor optimisation to hash_table doesn't bring much change, so generally no need to use them


// If we want to add resize and load factor optimisation we need to change the template 
typedef gp_hash_table<
    int, null_type, custom_hash, equal_to<int>, direct_mask_range_hashing<int>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<true>, true>>
    gp;

gp table;  // similar to unordered map of int,int
//custom_hash will stop blowing of complexity because of collision
// use custom_hash as done earlier
// also add extra optimisations
table.resize((1<<20)); // change as per required size
table.set_loads({.25,.5});


