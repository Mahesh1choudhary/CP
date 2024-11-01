/*
Idea 1- If we have to find something like max(|ai1-aj1|+|ai2-aj2|+....|aik-ajk|), then we can consider every possible sign
of each term, i.e. |ai1-aj1| has two possible values ai1-aj1 and -(ai1-aj1)
So in total we consider all possible 2^(k) options, and answer will be maximum of them ( can be easily proved- check editorial of Q1) 

Example - lets say we have k dimensional points, and we have to find two points with maximum manhattan distance
 point ai=[ai1,ai2,...aik], point aj=[aj1,aj2,...ajk]
 then find max(|ai1-aj1| + |ai2-aj2|.....+|aik-ajk|)

 Q1 - https://codeforces.com/problemset/problem/1093/G







Idea 2 - In some cases, if we need to answer path queries on tree, we can find euler tour( writing vertices both entering time and exit time). To Answer a query
 [l,r], we know all vertices on path between l and r will lie between (assuming l is ancestor of r) in_time[l] and in_time[l], but some vertices doesn't belong to the 
 becauses all vertices in subtree of l will be there. But we know that the vertices which are not in this path will be present two times in this range. So we can use this idea
 to remove the contribution of vertices which occurs two times in the given range.
 This idea could be useful in some cases, not in all cases or always.
  -> mentioned here - https://codeforces.com/blog/entry/43230



Idea 3 - Trick from virtual tree concept. if we have k vertices of a tree ,then maxnimum number of ancestors is k-1, and to find this , we should consider vertices in order of dfs time




Idea 4 - For ceil(a/b) , where a is known, there are only O(root(a)) possible values of ceil(a/b)
let A= floor(root(a)) then values are 1 ,2, 3.... A (A values), and ceil(a/1), ceil(a/2)...ceil(a/A) ( A values)
Related Question - https://codeforces.com/problemset/problem/830/C

 same for floor(a/b)
 so in general there are O(root(a)) possible value of a/b where a is known and b is unknowns


  



















*/