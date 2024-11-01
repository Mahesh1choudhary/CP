


// LINK1 - Theory - https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/


// LINK2 - Algorithms and different cases - https://codeforces.com/blog/entry/337



// For directed Graph, everything is same as that of undirected part, ust take care while using graph[k][j], if we need to end at j and earlier ending at k, then edge should be from k to j

// If we find dp, then we can easily restore the path
//// For undirected graph
int graph[n][n]; // graph[i][j]=1, if there is an edge between them, if weighted then graph[i][j] gives weight of edge

=>////  PART 1 - CHECK IF HAMILTONIAN PATH EXIST IN UNWEIGHED UNDIRECTED GRAPH;
bool dp[(1<<n)][n];// dp[mask][i]- we have path covering vertices in subset mask and ending at vertex i

// O(n*n*2^n) time comolexity, O(n*2^n) memory complexity
bool hamiltonian_path(){
    // first fill all with false
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++) dp[mask][i]=false;
    }

    // single vertex is a hamiltonina path
    for(int i=0;i<n;i++) dp[(1<<i)][i]=true;

    // check for all subsets in increasing order
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                for(int j=0;j<n;j++){
                    if(j!=i &&  (mask>>j)&1  && graph[j][i]){
                        dp[mask][i]=(dp[mask][i]|dp[mask^(1<<i)][j]);
                    }
                }
            }
        }
    }

    // check if a hamiltonian path exists , ending at some vertex
    for(int i=0;i<n;i++){
        if(dp[(1<<n)-1][i]) return true;
    }
    return false;
}

// Improved complexity- O(n*2^n) time complexity, O(2^n) memory complexity
int dp[1<<n] // dp[x] = mask of the subset consisting of those vertices j for which there exists a hamiltonian walk/paht over the subset x ending in j
// this new dp[mask]= sum over all i in old_dp[mask][i]*2^i

int M[n]; // M[i]= sum over all j , (2^j)*1 if there is (i,j) edge (j->i for directed graphs), 0 otherwise
// M[i]= subset of vertices incident to vertex i

bool hamiltonian_path(){
    // fill all states with 0
    for(int i=mask;i<(1<<n);i++) dp[mask]=0;   

    // fill all single vertices with 2^i;
    for(int i=0;i<n;i++){
        dp[(1<<i)]=(1<<i);
    }

    for(int mask=0;mask<(1<<n);i++){
        for(int i=0;i<n;i++){
            if((mask>>i)&1  &&  dp[mask^(1<<i)]&M[i]){
                dp[mask]+=(1<<i);
            }
        }
    }
    
    if(dp[(1<<i)-1]!=0){
        return true;
    }
    else return false;
}







//// PART 2 - SEARCH FOR SHORTEST HAMILTONIAN WALK IN UNDIRECTED WEIGHTED GRAPH
// hamiltonian path with minimum sum of weights

int dp[n][n]; // dp[mask][i]- length of shortest hamiltonian path consisting of vertices in subset mask and ending at vertex i
// O(n*n*2^n) time comolexity, O(n*2^n) memory complexity
int hamiltonian_path(){
    // fill all states with INF
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++) dp[mask][i]=INF;
    }

    // fill single vertices with 0
    for(int i=0;i<n;i++) dp[(1<<i)][i]=0;

    // fill other states in increasing order of i
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                for(int j=0;j<n;j++){
                    if(j!=i && (mask>>j)&1  && graph[j][i]>0){
                        dp[mask][i]=min(dp[mask][i],dp[mask^(1<<i)][j]+graph[j][i]);
                    }
                }
            }
        }
    }
    
    int ans=INF;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[(1<<n)-1][i]);
    }
    return ans;
}


//// PART 3 - FINDING NUMBER OF HAMILTONIAN WALKS
int dp[n][n]; // dp[mask][i]- no of hamiltonian path consisting of vertices in subset mask and ending at vertex i
// O(n*n*2^n) time comolexity, O(n*2^n) memory complexity
int hamiltonian_path(){
    // fill all states with 0
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++) dp[mask][i]=0;
    }

    // fill single vertices with 1
    for(int i=0;i<n;i++) dp[(1<<i)][i]=1;

    // fill other states in increasing order of i
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                for(int j=0;j<n;j++){
                    if(j!=i && (mask>>j)&1  && graph[j][i]>0){
                        dp[mask][i]+=dp[mask^(1<<i)][j];
                    }
                }
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans=dp[(1<<n)-1][i];   // if i is not in mask, then dp[mask][i] will be zero, so no need to check if i is set in mask
    }
    return ans;
}



/// PART 4 -> FINDING NUMBER OF SIMPLE PATHS;
// O(n*n*2^n) time complexity, O(n*2^n) space complexity
/*
Find the dp from part 3
*/
long long ans=0;
for(int mask=0;mask<(1<<n);mask++){
    int cnt=0;
    for(int i=0;i<n;i++){
        if((mask>>i)&1) cnt++;
    }
    if(cnt<2) continue;
    // there should be atleast two vertices for a simple path
    for(int i=0;i<n;i++){
        ans+=dp[mask][i];  // if i is not in mask, then dp[mask][i] will be zero, so no need to check if i is set in mask
    }
}
ans/=2;
















// Good questions -> https://codeforces.com/problemset/problem/1102/F
