// LINK 1 - https://cp-algorithms.com/data_structures/deleting_in_log_n.html
// LINK 2 - https://usaco.guide/adv/offline-del?lang=cpp#dsu-with-rollback
// LINK 3 - https://codeforces.com/edu/course/2/lesson/7/3

/*
For dynamic connectivity problems, we say for every query, there's an interval [l, r]
 where it's active. Obviously, for each edge add/remove query, l =(the index of the query which adds the edge), and 
r =(the index of the query which removes the edge) -1. If an edge never gets removed, then r = q - 1. We are using 0-based indexing
*/