







// METHOD 1- > check all number from 1 to root(n), if number d is divisor of n, then n/d will also be divisor
// O(root(n))
void find_divisors(int n){
    vector<int> divisors;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            divisors.pb(d);
            divisors.pb(n/d);
        }
    }
}


// Method 2 -> if we know prim factorization of number, then we can find divisors in O(n^(1/3)) as done in template- Generating divisors from prim factorizations







