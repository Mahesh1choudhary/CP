#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;


// IF WE WANT TO HANDLE BOTH CASES - COPRIME OR NON COPRIME MODULI, WE CAN USE BELOW METHOD

/*
In general case, a system of congruences has exactly one solution modulo lcm(m1, m2, m3,.... mk) or has no solution at all


*/
// Algorithm -> take two equations at a time and convert into new one by considering them as linear diophantine equations, till there is only one and find its solution
// LINK -> https://codeforces.com/blog/entry/61290


long long LCM(long long a, long long b){
    return (a/gcd(a,b))*b;
}

long long extended_gcd(long long a, long long b, long long& x, long long& y){
    if(b==0){
        x=1, y=0;
        return a;
    }
    long long x1, y1;
    long long d=extended_gcd(b, a%b, x1, y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

long long normalise(long long x,long long mod){
    x%=mod;
    if(x<0) x+=mod;
    return x;
}


//  RECHECK, MAYBE THERE ARE ERRORS IN CODE
// below we will also handle overflows
// O(nlog(LCM(m1,m2,m3,...mn))), where n= no of congruences
long long chinese_remainder_theorem(vector<pair<long long,long long>> congruences){
    // congruences[i]={ai,mi};
    int n=congruences.size();

    // normalising all congruences
    for(int i=0;i<n;i++){
        congruences[i].first=normalise(congruences[i].first, congruences[i].second);
    }
    long long ans=congruences[0].first;
    long long lcm=congruences[0].second;

    for(int i=1;i<n;i++){
        long long ai=congruences[i].first, mi=congruences[i].second;          

        // ans=a1, ai=a2, m1=lcm, m2=mi -> in terms of two equations-> a=a1+k1*m1, a=a2+k2*m2
        // a=ans+k1*lcm , a=ai+k2*mi
        // eq1 - eq2  => ans-ai= k2*mi+lcm*(-k1) -> this is now a linear diophantine equation
        // also from extended euclid algorithm, lcm*x+mi*y = gcd(lcm,mi)
        // so if (ans-ai) is not divisible by gcd(lcm,mi), then there is no solution, otherwise there is solution till now

        long long x,y;
        long long g=extended_gcd(lcm,mi,x,y);  
        if((ans-ai)%g!=0){
            cout<<"NO Solution"<<endl;
            return;
        }
        // lcm*x + mi*y = g
        // multiplying both sides by (ans-ai)/g
        // lcm*x*((ans-ai)/g) + mi*y*((ans-ai)/g) = ans-ai
        // comparing with lcm*(-k1) + k2*mi = ans-ai gives
        // k1= -x*((ans-ai)/g), k2= y*((ans-ai)/g),  ans solution is a=ans+k1*lcm =>  a=ans-x*((ans-ai)/g)*lcm

        // since numbers can be quite large, to stop overflow, we will perform calculations modulo LCM(lcm,mi)
        ans=normalise(ans- ((x*(ans-ai)/g)%(mi/g))*lcm, lcm*mi/g);
        
        lcm=lcm*mi/g;
    }
    cout<<ans<<" "<<lcm<<endl; // a= ans+k*lcm, k= ... -2, -1, 0, 1, 2 ...

}




























/*
If m=m1*m2*...mk , where mi are pairwise COPRIME, We also have equations
a = a1 (mod m1)
a=  a2 (mod m2)
.
.
a= ak (mod mk)
then  given system of equations has only one and exactly one solution under modulo m, ( without modulo, infinitely many solutions as solution+-k*m is also solution)
given by 
a = (summation from i=1 to k of   ai*Mi*Ni)  mod m
where Mi = m1*m2*..m(i-1)*m(i+1)*...mk = product of all mj except i
and Ni = modular inverse of Mi under mod mi

we can also say the reverse
x = a (mod m) is equivalent to
x = a1 (mod m1), where a1 = a (mod m1)
x= a2 (mod m2), where a2 = a (mod m2)
.
.
x = ak (mod mk)
where m= m1*m2*....mk and mi are pairwise coprime

*/
// When mi are coprime
long long mod_inverse(long long a, long long mod){
    long long b= mod-2;
    a%=mod;
    long long res=1;
    while(b>0){
        if(b&1==1){
            res=(res*a)%mod;
        }
        b=(b>>1);
        a=(a*a)%mod;
    }
    return res;
}

// nlog(max(mi)), where n is size of congruences
long long chinese_remainder_theorem(vector<pair<long long,long long>> congruences){
    // congruences[i]= (ai,mi)

    long long M=1;
    for(auto p:congruences){
        M*=p.second;
    }

    long long solution =0;
    for(auto p:congruences){
        long long ai=p.first;
        long long mi=p.second;
        long long Mi = M/mi;
        long long Ni= mod_inverse(Mi,mi);
        solution = (solution + (ai*Mi%M)*Ni)%M;
    }
    return solution;
}




// SOLUTION FOR NOT COPRIME MODULI
/*
In the not coprime case, a system of congruences has exactly one solution modulo lcm(m1, m2, m3,.... mk) or has no solution at all

since mi = p1^n1 * p2^n2 * .... pk^nk (prime factorization) ,  we can write a equation a= ai (mod mi) into k equation of type a= aij (mod pj^nj), where aij= ai (mod pj^nj)
using this we convert system of given congruences into a system, that only has prime powers as moduli.

Because originally some moduli had common factors, we will get some congruences moduli based on the same prime, however possibly with different prime powers.
the congruence with the highest prime power modulus will be the strongest congruence of all congruences based on the same prime number. Either it will give a contradiction with some other congruence, or it will imply already all other congruences.

If there are no contradictions, then the system of equation has a solution. We can ignore all congruences except the ones with the highest prime power moduli. These moduli are now coprime, and therefore we can solve this one with the earlier algorithm

*/




























