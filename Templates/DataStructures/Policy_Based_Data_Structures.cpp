#include <bits/stdc++.h>
using namespace std;





// LINK -  https://codeforces.com/blog/entry/11080



// headers for policy based data structures
#include <ext/pb_ds/assoc_container.hpp> // common file
#include <ext/pb_ds/tree_policy.hpp>  // including tree_order_statistics_node_update

using namespace __gnu_pbds;


//The tree-based container has the following declaration:

	  template<
	  typename Key, // Key type
	  typename Mapped, // Mapped-policy
	  typename Cmp_Fn = std::less<Key>, // Key comparison functor
	  typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
	  template<
	  typename Const_Node_Iterator,
	  typename Node_Iterator,
	  typename Cmp_Fn_,
	  typename Allocator_>
	  class Node_Update = null_node_update, // A policy for updating node invariants
	  typename Allocator = std::allocator<char> > // An allocator type
	  class tree;


// For set of T
typedef tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;


ordered_set<int> st;
// Two new functions 
// find_by_order(k) return iterator to the k the smallest element( counting from zero) or element at index i in sorted order ( 0-indexed)
st.find_by_order(k);
// order_of_key(t) return of items in a set that are strictly smaller than t or index of t
st.order_of_key(t);


// For multiset  => use pair<T,int> as a key where the second element in pair is the time when item has been added. => https://codeforces.com/blog/entry/11080?#comment-258244
//Main idea is to keep pairs like {elem, id}.

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int t = 0;

ordered_set me;


me.insert({x, t++});
me.erase(me.lower_bound({x, 0}));
cout << me.order_of_key({x, 0}) << "\n";