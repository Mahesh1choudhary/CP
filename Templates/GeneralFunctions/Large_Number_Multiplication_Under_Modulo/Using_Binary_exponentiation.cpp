// Finding (a*b)%mod, for large a and b -> useful when __int128 is not supported in the compiler
// O(logb);
long long mult(long long a, long long b, long long mod){
    long long res=0;
    while(b>0){
        if(b&1){
            res=(res+a)%mod;
        }
        a=(a+a)%mod;
        b/=2;
    }
    return res;
}


