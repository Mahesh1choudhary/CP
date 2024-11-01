// https://usaco.guide/adv/offline-del?lang=cpp#dsu-with-rollback

// DSU WITH ROLLBACK- we will store information that changes at each merge operation in stack or vector.
// the state of DSU is defined by the size of this stack or vector

// the information that changes will be size of one node and parent or id of other node

// no need to back path compression because complexity will be same even if we use it,but in rollback there will be
// lot more efforts and time constant increases.

class DSU_with_rollback{
    vector<int> id, sz;
    vector<pair<int &,int>> history;

    DSU_with_rollback(int n): id(n),sz(n,1){for(int i=0;i<n;i++) id[i]=i;}

    int root(int x){
        while(id[x]!=x) x=id[x];
        return x;
    }

    void merge(int a, int b){
        a=root(a), b=root(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);

        // saving information of this merge step- sz[a] and id[b] will change because of merge by size
        history.push_back({sz[a],sz[a]});
        history.push_back({id[b],id[b]});
        // first value is by reference so it changes with change in sz[a] and id[b] in later steps, but second value
        // will remain same as we put now

        id[b]=a, sz[a]+=sz[b];
    }

    // rollback till sz of history becomes until
    // two rollback by one operation, we need to remove two times from history vector
    void rollback(int until){
        while((int)history.size()>until){
            history.back().first=history.back().second; // restoring to previous value
            history.pop_back();
        }
    }

    void single_rollback(){
        if(history.empty()) return;
        history.back().first=history.back().second; // restoring to previous value
        history.pop_back();
        history.back().first=history.back().second; // restoring to previous value
        history.pop_back();
    }

}

// in place of history= vector<pair<int&,int>>, we could history= vector<vector<int>>, where each element is of size four a,id[a], b, sz[b], if we sz[a]<sz[b] during union







//  FOR MORE GENERAL APPROACH CHECK- rollback_general.cpp or this link - https://cp-algorithms.com/data_structures/deleting_in_log_n.html