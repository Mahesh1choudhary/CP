


// LINKS
// LINK1 - https://cp-algorithms.com/graph/2SAT.html
// LINK2 - https://codeforces.com/blog/entry/92977
// LINK3 - https://codeforces.com/blog/entry/16205

/* In 2-SAT, each clause has 2 literals and each variable has two possible values
 After creating graph of implications, if for any variable x, x and ~x are in the same SCC(strongly connected component), then there is no solution
Otherwise there is solution.

Algorithm-> Creating implication graph (let there are n variables and m edges or implications)
Find all strongly connected components. 
Sort all SCCs in topological order. let comp[x] denotes index of SCC to which x belongs
Check if solution exists ot not using above mentioned criteria ( For at least one x , comp[x]==comp[~x], then does not exists, otherwise exists)
if comp[x]<comp[~x], then assign x with false and ~ with true, otherwise assign x with true and ~x with false

O(m+n)
*/

// Implementations - similar to LINK1

int n;  // if we assume vertices to be 1-indexed, then n is even, and xi=i, ~xi=n/2+i
vector<vector<int>> graph, tgraph;  // graph and transposed graph
vector<int> toposort;
vector<bool> visited;
vector<int> compo; // component no of vertex
vector<bool> assignment;

void dfs1(int i){
    visited[i]=true;
    for(int v:graph[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    toposort.pb(i);
}


void dfs2(int i,int cnt){
    compo[i]=cnt;
    component.push_back(i);
    for(int v:tgraph[i]){
        if(compo[v]==-1){
            dfs2(v,cnt);
        }
    }

}

bool solve_2SAT(){
    // assuming vertices are 1-indexed
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    reverse(toposort.begin(),toposort.end());

    int cnt=0; // no of components
    for(int v:toposort){
        if(compo[v]==-1){
            dfs2(v,cnt++);
        }
    }
	
    for(int i=1;i<=n/2;i++){
        if(compo[i]==comp[n/2+i]){
            return false;
        }
        if(compo[i]>compo[n/2 +i]){
            assignment[i]=true;
            assignment[n/2 +i]=false;
        }
        else{
            assignment[i]=false;
            assignment[n/2 +i]=true;
        }
    }
    return true;
}

// function to add disjunction (a or b)
// na and nb signify whether a and b are to be negated
void add_disjunction(int a, bool na, int b, bool nb){
    int x, negx, y, negy;
    if(!na){
        x=a, negx= a+n/2;
    }
    else{
        x=a+n/2 , negx=a;
    }
    if(!nb){
        y=b, negy= b+n/2;
    }
    else{
        y=b+n/2 , negy=b;
    }
    graph[negx].push_back(y);
    graph[negy].push_back(x);
    tgraph[y].pb(negx);
    tgraph[x].pb(negy);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph=vector<vector<int>>(2*n+1,vector<int>());
    tgraph=vector<vector<int>>(2*n+1,vector<int>());

    // add disjunctions

    solve_2SAT();

	
	return 0;
}

