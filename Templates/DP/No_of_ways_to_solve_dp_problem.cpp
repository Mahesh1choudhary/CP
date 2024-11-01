/*\
there are many ways to solve a dp -> check code of all these method in math/linear recurrences folder
lets say 
dp[i] = sum over 1<=j<=i-1 ->dp[j]
first method- normal linear method of computing -> O(n*n);
second method- using matrix eponentiation - O(n*n*n*logn)
third method - cayley hamilton theorem - O(n*n*logn);

since for above dp case , second and third method are more costly, but for dps like below

dp[i][j]= sum over 1<=k<=n (or some of these k) -> dp[k][j-1];
i<=n and j<=m and n is very very less than m
then second and third method are better to use
second method - O(n*n*n*logm)

*/

// Good question -  https://codeforces.com/problemset/problem/691/E