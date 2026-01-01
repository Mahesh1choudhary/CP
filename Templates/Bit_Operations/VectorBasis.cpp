#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;
// link to blog- https://codeforces.com/blog/entry/68953
// we have n vectors in mod 2 and with d cordinate for each vector, so
//maximum size of basis can be d
//each vector will be represented using bitmask of length d

int basis[d]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(int mask) {
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}

//function to check if vector mask is representable by the linear combination of basis found till now
bool representable(int mask){
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue;

		if (!basis[i]) { 
			return false;
		}

		mask ^= basis[i];
	}
	return true;
}


int main(){
    vector<int> masks(n); // n vectors given in form of mask , now find the basis
    for(int i=0;i<n;i++){
        insertVector(masks[i]);
    }
    // if basis[i]>0, then mask at basis[i] is one of the vector of the basis

    return 0;
}



/*

Q1 - https://codeforces.com/problemset/problem/845/G
Q2 - https://codeforces.com/problemset/problem/1902/F


*/













