#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// This question and its implementation is very good ->  https://codeforces.com/contest/1792/problem/E

// 
vector<pair<int,int>> prime_divisors;   // contains count of each prime in the factorization of n
// the prime factorization here is in increasing order, that first cnt of 2, then 3,5,7 and so on, if prime p doesn't divide n, then it is not added in this vector
// If prime factorization is not in sorted order, the divisors generated will not be in sorted order
// 1-should not be included in prime factorization

// First generate prime factorizations- we can use any algorithm as per the required complexity
// Generating all divisors from prime factorization in O(number of divisors);

vector<pair<int,int>> prime_divisors;   // prime factor, count of prime factor
vector<LL> divisors;
void gen_divisors(int pos, LL val){ // current index, value formed till now
    if(pos>=prime_divisors.size()){
        divisors.push_back(val);
        return;
    }
    LL cur=val;
    for(int pwr=0;pwr<=prime_divisors[pos].second; pwr++){
        gen_divisors(pos+1, cur);
        if(pwr<prime_divisors[pos].second){
            // as we are multiplying at pwr=0;
            cur*=prime_divisors[pos].first;
        }
    }

}


// if n can we written as m1*m2, then generally finding all divisors or prime factors of n can be done in root(n)=root(m1*m2)
//But by taking advantage of n=m1*m2, we can do it in root(m1+m2)

// prime factorization of n in O(root(m1+m2));
void find_factors(LL n, LL m1, LL m2){

    for(int d=2;d*d<=m1 || d*d<=m2;d++){
        int cnt=0;
        while(m1%d==0){
            m1/=d;
            cnt++;
        }
        while(m2%d==0){
            m2/=d;
            cnt++;
        }
        if(cnt>0) prime_divisors.push_back({d,cnt});
    }
    if(m1>m2) swap(m1,m2);
    if(m1>1) prime_divisors.push_back({m1,1});
    if(m2>1){
        if(m2==m1){
            prime_divisors.back().second++;
        }
        else{
            prime_divisors.push_back({m2,1});
        }
    }

}














void main(){

    gen_divisors(0,1);

}

