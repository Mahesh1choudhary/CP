#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;
// Also read about XOR hashing.

// LINK - https://cp-algorithms.com/string/string-hashing.html
// using hashes, string comparisons can be reduced to O(1) instead of O(min(n1,n2)), where n1, n2 are string lengths

// If we are using rolling hash, and m is chosen as prime, If we comapre two strings with max(s1.length(),s2.lenght())=k, then probability of collision is k/m, not 1/m
// LINK -> https://codeforces.com/blog/entry/60442,  https://usaco.guide/gold/string-hashing

// IN QUESTIONS, SELECT P RANDOMLY WITH A HIGH PRECISION CLOCK TO AVOID GETTING HACKED
int p=31; // some prime number roughly equal to the number of characters in the input alphabet
int m=1e9+9;    // some large prime number, probability of collision in a single comparison is k/m (where k is maximum of lengths of the two strings to be compared), if we are doing n comparisons, then it is n*k/m
// But if we have hashes of n strings with max length of string is k, then  it is O(n*n*k/m) as we will do n*n comparisons

// here we use conversion a->1, b->2, c->3 .... z->26, 
s

// IMPROVING NO COLLISION PROBABILITY
// to get better probabilities, compute two different hashes for each string using two different p, and/or different m,
// and compare these pairs for similarity. The newprobability of collision becomes 1/(m1*m2)

// we can extend this idea to three or more hashes if needed
int p1=31, p2=37;
int m1=1e9+7  , m2= 1e9+9;

long long compute_hash(string s, int p, int m){
    long long hash_value=0;
    long long p_pow=1;
    for(char c:s){
        hash_value=(hash_value+1ll*(c-'a'+1)*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }
    return hash_value;
}





// LINK -> https://cp-algorithms.com/string/string-hashing.html#fast-hash-calculation-of-substrings-of-given-string
// FAST HASH CALCULATION OF SUBSTRINGS OF GIVEN STRING
// hash(s[i...j])*(p^i) = hash(s[0...j]) - hash(s[0....i-1])  mod m 


// Submethod 1 ->  hash(s[i...j]) = (hash(s[0...j]) - hash(s[0....i-1]))*((p^i)^-1)  mod m
// So knowing hash values of each prefix, we can compute hash value of any substring using above formula.
// we can either precompute all p^i inverses or can compute at the required time

// Submethod 2 -> rather than calculating the hashes of substring exactly, it is enough to compute the hash multiplied by some power of p.
// Suppose we have two hashes of two substrings, one multiplied by p^i and other by p^j. If i<j then we multiply the first hash by p^(j-i), otherwise
// we multiply the second hash by p^(i-j). then both hashes can be compared






// LINK -https://codeforces.com/blog/entry/60442
// ROLLING HASH
/* PART 1 -> RANDOMISING BASE P 
 To make solution less hackable, first find p using random number gneerator, and then find all hashes.
 In this case probablility of collision on n length strings=> Pr[h(s)==h(t)] <= (n-1)/m
*/


/* PART 2 -> RANDOMISING MODULO
fix p >= no of possible characters, and a bound N>p and pick a PRIME m uniformly at random from [N, 2*N-1]
Then probablility of collision => nln(p)/N
*/

//to randomise base or prime, use high precision time
seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
};
mt19937 rng(seq);
int base = uniform_int_distribution<int>(0, p-1)(rng);


// We can also use multiple hashes to decrease the probability of collision. In these multiple hashes with different parameters or if we are suing randome bases or mod, then just generate more bases or mods.
/* Using larger (60 bit) primes would make collision less likely and not suffer from the accumulated factors of n in the error bounds. However, the computation of the rolling hash gets slower and more difficult, as there is no __int128 on codeforces.
One exception to this is the Mersenne prime m = 2^61 - 1; we can reduce  by using bitshifts instead. The following code computes  without __int128 and is only around 5 % slower than a 30 bit hash with modulo.
*/
//For the arguments, the condition  0<=a,b < mod should hold. The return value then also satisfies this.
// a*b % mod
constexpr uint64_t mod = (1ull<<61) - 1;
uint64_t modmul(uint64_t a, uint64_t b){
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&mod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & mod) + (ret>>61);
	ret = (ret & mod) + (ret>>61);
	return ret-1;
}



/*  EXTENSION TO MULTIPLE COMPARISONS 
If we rely on m comparison and the probability that a single comparison fails is p then the probability that any of the fail is at most m·p by a union bound.
Note that when m = 10^5, we need at least two or three hashes for this to be small.

IF we have 1e9 order comparisons, then we need 3 or four normal hashes( m of order 1e9) or only two if we use m=2^61 -1 

*/


// also check unordered map and set file for hashing






//XOR hashing questions - https://codeforces.com/problemset/problem/1830/C