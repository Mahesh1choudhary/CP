// LINK1 - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
// LINK2 - https://codeforces.com/blog/entry/54090
// LINK3 - https://codeforces.com/blog/entry/53925

// SEIVES CAN BE USED TO FIND AOUT VALUES OF MULTIPLICATIVE FUNCTION IN [1,N] OR FOR FUNCTIONS INVOLVING PRIMES -> check LINK2 for idea
// THESE SEIVES ARE ALSO USEFUL IN MOBIUS INVERSION RELATED QUESTIONS  -> LINK3 -https://codeforces.com/blog/entry/53925

// PART 1 - SEIVE OF ERATOSTHENES - O(nloglogn) -  LINK - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#sieving-till-root
// example- finding all primes in [1,n]

int n;
vector<bool> is_prime(n+1,true);
is_prime[0]=is_prime[1]=false;
for(int i=2;i*i<=n;i++){
    if(is_prime[i]){
        for(int j=i*i;j<=n;j+=i){
            is_prime[j]=false;
        }
    }
}
// even if we use i<=n instead of i*i<=n, compleixty remains same


// PART 2 - SEGMENTED SEIVE -    
// LINK - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#segmented-sieve






// PART 3 - LINEAR SEIVE - O(n)
// LINK - https://codeforces.com/blog/entry/54090
// using same example - finding primes
int n;
vector<bool> is_prime(n+1,true);
vector<int> primes;
is_prime[0]=is_prime[1]=false;
for(int i=2;i<=n;i++){
    if(is_prime[i]) primes.push_back(i);
    for(int j=0;j<(int)primes.size() && i*prime[j]<=n; j++){
        is_prime[i*prime[j]]=false;
        if(i%prime[j]==0) break;
    }
}



/*  FOR FINDING VALUES OF MULTIPLICATIVE FUNTION f(x) for all x in 1 TO N, we need to consider 3 cases:-
if x is prime- we can determine the value of f(x) directly
if x=i*p and p does not divide i, then f(x)=f(i)*f(p) using multiplicative function property
if x=i*p and p divided i- In this case, we have to figure out a relationship between f(i) and f(i*p)
*/

//  EVEN IF WE CAN'T FIND RELATION IN f(i) and f(i*p) IN CASE 3 , WE CAN STILL A WAY TO APPLY LINEAR SEIVE GIVEN HERE - LINK2 -https://codeforces.com/blog/entry/54090

