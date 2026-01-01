// LINK 1 -> https://codeforces.com/blog/entry/98663
// LINK 2 -> https://codeforces.com/blog/entry/100910
// LINK 3 - https://codeforces.com/blog/entry/49812


// SUBSET SUM PROBLEM
//QUESTION -  n items each with weight wi, check if there is a subset of items with total weight=m;

// METHOD 1- time complexity- O(n*m) ,  space complexity - O(n*m)
bool dp[n+1][m+1]; // true- if possible to get sum of weight =j using first i items
for(int i=0;i<=n;i++)for(int j=0;j<=m;j++) dp[i][j]=false;
dp[0][0]=true;
for(int i=1;i<=n;i++){
    for(int j=0;j<=m;j++){
        dp[i][j]= (dp[i][j]|dp[i-1][j]);
        if(w[i]>=j) dp[i][j]=(dp[i][j]|dp[i-1][j-w[i]]);
    }
}
// In this appraoch we can recover the subset by defining dp[i][j] as parent of state {i,j} or -1 accordingly, in the same complexity
// time-O(m*n), space -O(m*n)




// METHOD 2 -> time complexity- O((n*m)/(32)), space complexity O(m)
bitset<m+1> dp(0)    // all values initialized with 0
// dp[i]=1 -> if possible to get sum of weight=i
dp[0]=1;
for(int i=1;i<=n;i++){
    dp=(dp|(dp<<w[i]));
}
/* In this method, we cant recover the subset within the same time and space complexity,
it can be done in O(n*m) time and O(n*m) space as in Method 1
*/




// METHOD 3 - CONDITION - if sum of all weights= W;
// time compelxity - O((W*(root(W)))/32), space complexity - O(W)

int cnt[W];
for(int i=0;i<=W;i++) cnt[i]=0;
for(int i=1;i<=n;i++) cnt[w[i]]++;
vector<int> new_weights;    // size of order O(root(W))
for(int i=1;i<=n;i++){
    if(cnt[i]==0) continue;;
    if(cnt[i]%2==0){
        cnt[2*i]+=(cnt[i]-2)/2;
        new_weights.eb(i);
        new_weights.eb(i);
    }
    else{
        cnt[2*i]+=(cnt[i]-1)/2;
        new_weights.eb(i);
    }
}

bitset<W+1> dp(0);
dp[0]=1;
for(int x:new_weights){
    dp=(dp|(dp<<x));
}
/*
To find the required subset - ( as per my current knowledge)
In this approach, we can find the subset in the following way:
step 1 - first we will find weights used in obtaining a certain weight
step 2 - then we will find cnt( cnt_ans array) of each weight( how many times weight w is used in obtaining given weight m )
step 3 -  since we have converted weight w into 2*w and so on. So if cnt_ans[w]> no of times weight w occurs in wi, we will take available w and convert remaining w-> cnt_ans[w/2]+=(cnt_ans[w]-cnt of available w)
step 4 - finally we can find the indices of elements with given wi

int dp[W+1];    // index(in new_weights array) of the last element used in obtaining weight i
for(int i=0;i<=W;i++) dp[i]=-1;
dp[0]=0;

for(int i=0;i<(int)new_weights.size();i++){
    for(int j=1;j<=W;j++){
        if(dp[j]!=-1) continue;
        if(dp[j-new_weights[i]]!=-1){
            dp[j]=i;
        }
    }
}

int z=m;
if(dp[z]==-1) return; // not possible
vector<int> cnt_ans[W];
while(z>0){
    cnt_ans[new_weights[z]]++;
    z-=new_weights[z];
}
int cnt2[W+1]  - same as array cnt before updating
// we can compressed down cnt_ans array if we need- but it does not affect compelxity
vector<pair<int,int>> ans
for(int i=W;i>=1;i--){
    if(cnt_ans[i]>cnt2[i]){
        ans.push_back({cnt2[i],i})  // weight i taking cnt2[i] times
        cnt_ans[i/2]+=2*(cnt_ans[i]-cnt2[i])
    }
    else{
        ans.push_back({cnt_ans[i],i});
    }
}

now find the indices of all all weights that we have taken

time complexity - O(W*root(W)), space complexity - O(W)

*/





// METHOD 4 -> CONDITION - each weight wi<= D
// O(n*D)











/*
trick 5 from LINK2 used in question -> https://codeforces.com/contest/981/problem/E





*/

























// REMOVING ELEMENTS FROM KNAPSACK
// LINK -> https://codeforces.com/blog/entry/100910
// Q1 -> https://codeforces.com/problemset/problem/981/E
// Q2 - https://codeforces.com/problemset/problem/1970/G3
// it can be used with O(w*root(w)) approach also - see Q2


