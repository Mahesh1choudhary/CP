/*
A graph is said to be 2-edge connected if, on removing any edge of the graph, it still remains connected, i.e. it contains no Bridges. 

FINDING TWO-EDGE CONNECTED COMPONENTS OR BRIDGE TREE

Find bridges in the graph and mark them.
Remove the bridge from the graph.
Run dfs/dsu or bfs whichever way you prefer to group one components and give vertices the component id in which they belong. (Note: Remove bridge means: while traversing make sure not to cross the bridge, so we can group vertices of one component)
Traverse every edge, if it is a bridge, connect the two components via an edge.


LINK 1- https://codeforces.com/blog/entry/83980
*/