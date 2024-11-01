
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// finding solutions of a*x+b*y=c

// degenerate case a=0, b=0 should be handled separately

// Solution using extended gcd method
/*
Using extended gcd => a*xg + b*yg =g, if c is not divisible by g, then no solution, otherwise
multiplying both sides by c/g, gives a*(xg*c/g) + b*(yg*c/g) = c
so x0 = xg*(c/g), y0=yg*(c/g); All other solution are given by x=x0 + k*(b/g), y=y0 - k*(a/g)
*/

int extended_gcd(int a, int b, int& x, int& y){
    if(b==0){
        x=1, y=0;
        return a;
    }
    int x1, y1;
    int d=extended_gcd(b, a%b, x1, y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

// we will also handle cases where a or b is negative
void find_solution(int a, int b, int c){
    int xg, yg, g;
    g=extended_gcd(abs(a),abs(b),xg,yg);
    
    if(c%g!=0){
        cout<<"NO solution"<<endl;
        return;
    }

    int x0=xg*(c/g), y0=yg*(c/g);
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
}


// FINDING NO OF SOLUTIONS AND THE SOLUTIONS IN A GIVEN INTERVAL
// findin solutions in intervals [minx,maxx] and [miny,maxy]
// Note- If a or b is zero, then problem has one solution

/* Find minkx (minimum value of k such that x= x0+k*b/g >=minx), maxkx, minky,maxky and take 
 intersection of [minkx,maxkx] and [minky, maxky]

*/

// minx <= x <= maxx, miny <= y <= maxy
void find_all_solution(int a, int b, int c, int minx, int maxx, int miny, int maxy){
    int xg, yg, g;
    g=extended_gcd(abs(a),abs(b),xg,yg);
    
    if(c%g!=0){
        cout<<"NO solution"<<endl;
        return;
    }

    int x0=xg*(c/g), y0=yg*(c/g);
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;

    a/=g;
    b/=g;

    int sign_a= a>0 ? +1 : -1;
    int sign_b= b>0 ? +1 : -1;
    
    int minkx, maxkx, minky, maxky;

    if(sign_b>0){
        minkx=(minx-x0)/(b);
        maxkx=(maxx-x0)/(b);
    }
    else{
        minkx=-(maxx-x0)/(abs(b));
        maxkx=-(minx-x0)/(abs(b));
    }

    if(sign_a>0){
        minky=-(maxy-y0)/(a);
        maxky=-(miny-y0)/(a);
    }
    else{
        minky=(miny-y0)/(abs(a));
        maxky=(maxy-y0)/(abs(a));
    }

    int kmin=max(minkx, minky), kmax=min(maxkx,maxky);
    if(kmin>kmax){
        cout<<"NO Solution in range"<<endl;
    }
    else{
        for(int i=kmin,i<=kmax;i++){
            cout<<(x0+i*(b))<<" "<<(y0-i*(a))<<endl;
        }
    }

}

/* solution with minimum x+y => x+y=x0+y0+k*(b-a)/g in a given interval
If b-a>0, select minimum possible key from the possible range
else if b-a<0, select maximum possible k from possible range
else if b=a, we will have constant value
*/












