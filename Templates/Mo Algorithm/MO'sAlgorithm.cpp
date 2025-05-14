#include <iostream>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;

// LINK -> https://cp-algorithms.com/data_structures/sqrt_decomposition.html 
// improvements -> Link ->  https://codeforces.com/blog/entry/61203

// For answering q range queries in offline mode (without updates)
// BASIC IDEA ->  first answer queries with left index in 0 th block , then 1st, and so on, within each block answer queries sorted by right index
// For this, we will maintain a single data structure as compared to sqaure root decomposition where we keep data structure in each block

===> No 1// Canonical version of algorithm

// Based on the problem we can use a different data structure and modify the add/remove/get_answer functions accordingly
// Overall complexity ->   (QlogQ) for sorting queries + (N+Q)*F*root(N) for answering queries = (N+Q)*F*root(N)
// Here F is complexity of add and remove functions

void remove(idx);  // TODO- implement as per given requirement -> remove value at idx from the data structure
void add(idx);      // TODO- ''           -> add value at idx from data structure
int get_answer();   //TODO- ''           ->  extract the current answer of the data structure

int block_size;     // size of the blocks

///// If block size is M, then actual time complexity O((qM+(n*n)/M)*F + q*G), where F is complexity of addition and removal and G is complexity of answering a query-> toal QM left pointer shift, total n*n/m shifts of right pointer, total q queries to answer
///  Since q*G is small as compared to other part, so it is ignored and complexity is O((qM+(n*n)/M)*F)
/// Here if we choose M=root(n), then O((q+n)*root(n)*F);
/// If we choose M=n/root(q), then O(n*root(q)), but Method no 2 outperforms this
/// If n/q >1 , then n*root(q) complexity or method 2 is best


struct Query{
    int l,r,idx; // idx= index of current query in array of queries

    // For sorting queries in array of queries;
    bool operator<(Query q){
        return make_pair(l/block_size,r)<make_pair(q.l/block_size,q.r);
        // sorting according to block no, in the same block sorting by min r to max r;
    }

}

vector<int> Mo_Algorithm(vector<Query> queries){
    vector<int> answers(queries.size());    // answer to the queries
    sort(queries.begin(),queries.end());    // < is defined in query class

    // TODO -> Initialize data structure

    int cur_l=0;
    int cur_r=-1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]

    for(Query q:queries){
        // ordering of while loops is important
        while(cur_l>q.l){
            cur_l--;
            add(cur_l);
        }
        while(cur_r<q.r){
            cur_r++;
            add(cur_r);
        }
        while(cur_l<q.l){
            remove(cur_l);
            cur_l++;
        }
        while(cur_r>q.r){
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx]=get_answer();
    }
    return answers;

}







==> Little optimisation

// sorting plays a important role in overall time complexity
// Usually, the two comparators for query sorting are used. The slowest one is as done previously
struct Query{
    int l,r,idx;

    bool operator<(Query q){
        return make_pair(l/block_size,r)<make_pair(q.l/block_size,q.r);
    }

}


//  It can be optimized a little if for even blocks we use the reverse order for the right boundary
struct Query{
    int l,r,idx;

    bool operator<(Query q){
        if(l/block_size !=q.l/block_size){
            return make_pair(l,r)<make_pair(q.l,q.r);
        }
        else{
            if((l/block_size)%2==1){
                return r<q.r;
            }
            else{
                return r>q.r;
            }
        }
    }
}











==> No 2    // Achieving better time complexity of O(n*root(q)) which is better than O((n+q)*root(n));
// We will use hilbert curve here



//// Assume the matrix has size 2^k × 2^k, where 2^k ≥ n (find minimal such k that 2^k ≥ n).
// Now denote oi as ord(li, ri, k) on this matrix. Then sort the queries according to their oi.
long long hilbertOrder(int x,int y,int pow,int rotate) {
	if(pow==0) {
		return 0;
	}
	int hpow= (1<<(pow-1));
	int seg=(x<hpow)?((y<hpow)? 0:3):((y<hpow)? 1:2);
	seg= (seg + rotate) & 3;
	const int rotateDelta[4] = {3,0,0,1};
	int nx= (x&(x^hpow)), ny = (y&(y^hpow));
	int nrot=((rotate+rotateDelta[seg])&3);
	long long subSquareSize= (long long(1) << (2*pow - 2));
	long long ans=seg*subSquareSize;
	long long add=hilbertOrder(nx,ny,pow-1,nrot);
	ans+= (seg==1 || seg==2) ? add:(subSquareSize -add- 1);
	return ans;
}

struct Query{
    int l,r,idx;
    long long ord;
    void calcOrder(){
        ord=hilbertOrder(l,r,k,0);// generally k=21 or find k such that 2^k>=n
    }
};
bool operator<(Query &a, Query &b){
    return a.ord < b.ord;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    vector<Query> queries(m);
    // m queries
    for(int i=0;i<m;i++){
        cin>>l>>r;  // l<=r;
        queries[i].l=l;
        queries[i].r=r;
        queries[i].idx=l;
        queries[i].calcOrder(); // to find ord value for query
    }

    sort(queries.begin(),queries.end());
	
    
	return 0;
}
