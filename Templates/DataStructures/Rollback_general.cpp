// GENERAL IDEA OF ROLLBACK - maintain a stack or vector storing memory cells that are changed and their original value
// while doing rollback, take last element of stack and gives original values to parameters and delete from stack


// https://cp-algorithms.com/data_structures/deleting_in_log_n.html
// If adding elements is O(T(n)) in true(not amortized), then deletion will be in O(T(n)logn) offline.


// https://usaco.guide/adv/offline-del?lang=cpp#dynamic-connectivity


/*
rollback realted questions - 
https://codeforces.com/problemset/problem/1858/E1



*/