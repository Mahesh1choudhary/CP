/*
LINK 1 - https://codeforces.com/blog/entry/98663
LINK 2 - https://codeforces.com/blog/entry/59606
LINK 3 - https://codeforces.com/blog/entry/63323 - for writing Method 1 using 1-d array
LINK 4 - https://codeforces.com/blog/entry/47247#comment-316200   - for finding used weights while using 1-d array for Method 1

*/

 
// PART 1 - BOUNDED KNAPSACK ( each item can be taken atmost one time)
// Question - given n items, ith item has weight wi and value vi. Find a set S of items such that sum over wi of set<= C and sum of vi of set is maximised


// METHOD 1
// time complexity - O(n*C), space complexity- O(n*C);

int dp[n+1][C+1];
for(int i=0;i<=n;i++) for(int j=0;j<=C;j++) dp[i][j]=0;

for(int i=1;i<=n;i++){
    for(int j=1;j<=C;j++){
        dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(j>=w[i]){
            dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
}
ans=0;
for(int j=0;j<=C;j++) ans=max(ans,dp[n][j]);

/* we can also solve this 1-d array as given in LINK 3 
int dp[C+1];
for(int i=1;i<=n;i++){
    for(int j=C;j>=0;j++){  // in reverse order, so that already updated values are not changed
        dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(j>=w[i]){
            dp[j]=max([j],dp[j-w[i]]+v[i]);
        }
    }
}
*/





// METHOD 2
// we can use the fact that if we have many items with weight w, then we can take maximum of C/w items only (C/w items with maximum value)
// so iterating over w=1 to C, we will consider only O(C*logC) elements only giving complexity of O(C*C*logC)
// time complexity - O(C*C*logC), space complexity - O(C)

int dp[C+1];    // maximum value obtained with sum ov weight =i
for(int i=0;i<=C;i++) dp[i]=0;
vector<int> vals[C+1];  // all values with weight =i
for(int i=1;i<=n;i++){
    vals[w[i]].emplace_back(v[i]);
}
for(int i=0;i<=C;i++) sort(vals[i].begin(),vals[i].end(),greater<int>());


for(int i=1;i<=C;i++){
    for(int j=0;j<=C;j++){
        int sumv=0;
        for(int k=0;k<(int)vals[i].size() && j+(k+1)*i<=C ;k++){
            sumv+=vals[i][k];
            dp[j+(k+1)*i]=max(dp[j+(k+1)*i], dp[j]+sumv);
        }
    }
}

ans=0;
for(int j=0;j<=C;j++) ans=max(ans, dp[j]);










