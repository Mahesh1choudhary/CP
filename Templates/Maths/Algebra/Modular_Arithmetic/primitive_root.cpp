#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back

using namespace std;

// LINK - https://cp-algorithms.com/algebra/primitive-root.html

// g is primitive root modulo n if for any a such that gcd(a,n)==1 or for any a which is coprime with n
// there exists an integer k such that power(g,k)= a (mod n);
// k is called index or discrete logarithm of a to base g modulo n

// primitive root modulo n exists only if  n=1,2,4; n is power of odd prime number( n=power(p,k)); n is
// twice power of an odd prime number (n=2*power(p,k));

// let g be primitive root modulo n, then smallest number k for which power(g,k)=1 (mod n) is phi(n) ( euler's toitent function)
// and reverse is also true;
// number of primitive roots modulo n, if there anre any is equal to phi(phi(n));


//Incomplete


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	
	
	
	return 0;
}