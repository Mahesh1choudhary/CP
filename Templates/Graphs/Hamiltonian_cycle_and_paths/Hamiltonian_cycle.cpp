

// If Hamiltonian cycle exists, then each vertex is in there, so we can assume any vertex as starting vertex
// if we choose i to be starting vertex , then put dp[(1<<i)][i]=1, true or some value accordingly


// ALL BELOW ARE FOR UNDIRECTED GRAPH, FOR DIRECTED GRAPH, WE ONLY HAVE TO BE CAREFUL WHILE CHECKING EDGE BETWEEN i AND j
// IF EARLIEAR IT ENDS AT j AND NOW WE NEED TO CHECK IF IT ENDS ON i , THEN THERE SHOULD BE EDGE j->i

// We can also easily restore the cycle if it exists

// PART 1 -> CHECK IF HAMILTONIAN CYCLE EXITS
// time complexity - O(n*n*2^n), space complexity - O(n*2^n)
bool dp[(1<<n)][n]; // dp[mask][i] -> true if there is hamiltonian walk/path over vertices in mask , starting at 0 and ending at i
// time complexiyt - O(n*n*2^n), space complexity - O(n*2^n)
int hamiltonian_cycle(){
    // setting all staes to false;
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++) dp[mask][i]=false;
    }

    // setting vertex 0 as starting vertex
    dp[(1<<0)][0]=true;

    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                for(int j=0;j<n;j++){
                    if(j!=i && (mask>>j)&1  && graph[j][i]){
                        dp[mask][i]= dp[mask,i]|dp[mask^(1<<i)][j];
                    }
                }
            }
        }
    }

    
    for(int i=1;i<n;i++){
        if(graph[i][0]){
            if(graph[i][0] && dp[(1<<n)-1][i]){
                return true;
            }
        }
    }
    return false;
}

// Improved, time complexiyt - O(n*2^n), space complexity - O(2^n)
int dp[1<<n] // dp[x] = mask of the subset consisting of those vertices j for which there exists a hamiltonian walk/path over the subset x, starting at 0 ending in j
// this new dp[mask]= sum over all i in old_dp[mask][i]*2^i

int M[n]; // M[i]= sum over all j , (2^j)*1 if there is (j,i) edge (j->i for directed graphs), 0 otherwise
// M[i]= subset of vertices incident to vertex i
bool hamiltonian_cycle(){
    // fill all states with 0
    for(int i=mask;i<(1<<n);i++) dp[mask]=0;   

    // setting 0 as starting vertex ( we can set any one vertex as starting vertex, then we have to chanve values accordingly)
    dp[(1<<0)]=(1<<0);

    for(int mask=0;mask<(1<<n);i++){
        for(int i=0;i<n;i++){
            if((mask>>i)&1  &&  dp[mask^(1<<i)]&M[i]){
                dp[mask]+=(1<<i);
            }
        }
    }
    
    if(dp[(1<<i)-1]!=0 && dp[(1<<i)-1]&M[0]){
        return true;
    }
    else return false;
}




/// PART 2 -> FINDING SHORTEST HAMILTONIAN CYCLE
// assuming 0 is the starting vertex

int dp[(1<<n)][n]; // dp[mask][i] -> length of shortest hamiltonian walk/path over vertices in mask , starting at 0 and ending at i
// time complexity - O(n*n*2^n), space complexity - O(n*2^n)
int hamiltonian_cycle(){
    // setting all staes to INF;
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++) dp[mask][i]=INF;
    }

    // setting vertex 0 as starting vertex
    dp[(1<<0)][0]=0;

    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                for(int j=0;j<n;j++){
                    if(j!=i && (mask>>j)&1  && graph[j][i]){
                        dp[mask][i]=min(dp[mask][i], dp[mask^(1<<i)][j]+dist[j][i]);
                    }
                }
            }
        }
    }

    int ans=INF;
    for(int i=1;i<n;i++){
        if(graph[i][0]){
            ans=min(dp[(1<<n)-1][i]+d[i][0]);
        }
    }

    return ans;
    // if ans=INF-> no hamiltonian cycle
}



/// PART 3 - FINDING THE NUMBER OF HAMILTONIAN CYCLE
// dp[mask][i]-> no of hamiltonian walk/[ath with vertices in mask and ending at i and starting at 0]
// time complexity - O(n*n*2^n), space complexity - O(n*2^n)
int hamiltonian_cycle(){
    // fill all states with 0
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++) dp[mask][i]=0;
    }

    // fill 0 vertex with 1
    dp[(1<<0)][0]=1;

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
    for(int i=1;i<n;i++){
        if(graph[i][0]) ans=dp[(1<<n)-1][i];  // if i is not in mask, then dp[mask][i] will be zero, so no need to check if i is set in mask
    }
    return ans;

} 





/// PART 4 - FINDING NUMBER OF SIMPLE CYCLES
// time complexitY - O(n*n*2^n), space complexity - O(n*2^n)
// dp[mask][i] -> number of hamiltonian walks over the subset mask, starting 






