#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Link -> https://cp-algorithms.com/algebra/discrete-log.html

// a^x = b (mod m), finding x using baby-step giant-step (meet in the middle)



// Case 1 -> general case - whether a is coprime or not - doesn't matter
// if b is not divisible by gcd(a,m), then there is no solution, otherwise we check if there is solution or not
/* a^x = b (mod m) => (g*a')(a)^(x-1) = g*b' (mod g*m') gives a'*a^(x)=a*b' (mod m')
if x=pn-q where p belong to [1 to ceil(m/n)] and q belongs to [0 to n]
    a'*a^(pn) = a*b'*a^q => compute all possible values of left side, then of right side to check if values matches
*/


// O(log(min(a,b)))
int gcd(int a, int b){
    while(b>0){
        a=a%b;
        swap(a,b);
    }
    return a;
}
int power(int a, int p, int m){
    int res=1;
    while(p>0){
        if(p&1){
            res=(res*1ll*a)%m;
        }
        p/=2;
        a=(a*1ll*a)%m;
    }
    return res;
}

// O(sqrt(m)logn(m)) if ordered_map is used, O(sqrt(m)) if unordered map is used
int discrete_log(int a, int b, int m){

    // handling a=0 case separetely
    if(a==0){
        return b==0 ? 1: -1;
    }

    a%=m, b%=m;
    int g= gcd(a,m);
    if(b%g){
        cout<<"NO Solution"<<endl;
        return -1;
    }
    int a_=a/g;
    b/=g, m/=g; // a_= a'

    int n = sqrt(m)+1;
    map<int,int> vals; // if we need all solution or to find x, then use map<int,vector<int>> as different p can map to the same value
    
    int apow=power(a,n,m);// a^n -> to reduce log factor for finding a^p every time in below loop
    
    // O(nlogn) with ordered_map, O(n) with unordered_map
    int cur=a_;
    for(int p=1;p<=n;p++){
        cur=(cur*1ll*apow)%m;
        vals[cur]=p;
    }

    int ans=-1;

    // O(nlogn) with ordered map, O(n) with unordered map
    cur=a*b ;     // a*(b/g) = a*b'
    for(int q=0;q<=n;q++){
        if(vals.count(cur)>0){
            int p=vals[cur];
            ans= n*p-q;
            return ans;
        }
        cur=(cur*1ll*a)%m;
    }

    return -1;  // no solution
}



// case 2 -> simple case , when a and m are coprime
// a^np = b*a^q;
int discrete_log(int a, int b, int m) {
    // handling a=0 case separetely
    if(a==0){
        return b==0 ? 1: -1;
    }


    a%=m, b%=m;
    int n=sqrt(m) + 1;

    map<int,int> vals; // if we need all solution, then use map<int,vector<int>>
    
    int apow=power(a,n,m);// a^n -> to reduce log factor for finding a^p every time in below loop
    
    // O(nlogn) with ordered_map, O(n) with unordered_map
    int cur=1;
    for(int p=1;p<=n;p++){
        cur=(cur*1ll*apow)%m;
        vals[cur]=p;
    }

    int ans=-1;

    cur=b;     // b*a^q
    for(int q=0;q<=n;q++){
        if(vals.count(cur)>0){
            int p=vals[cur];
            ans= n*p-q;
            return ans;
        }
        cur=(cur*1ll*a)%m;
    }

    return -1;  // no solution
}

























