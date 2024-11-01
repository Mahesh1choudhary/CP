//Question - https://codeforces.com/problemset/problem/933/B


//Theory - https://en.wikipedia.org/wiki/Negative_base



// Calcualtion
// writing p in base -k


vector<long long> ans;
while(p!=0){
    long long rem= p%(-k);
    p/=(-k);
    if(rem<0){
        rem+=k;
        p+=1;
    }
    ans.emplace_back(rem);
}

for(long long x:ans) cout<<x<<" ";
cout<<endl;



