/*

TRICK 1 - Especially in graph-traversal or DP problems, you may be calling a subroutine multiple times, needing to initialize an array each time
In cases where this re-initialization is the bottleneck of your program, or if your implementation is just slightly too slow to pass in time,
it can be improved by using a sentinel and avoiding re-initialization each time
The only change would be that instead of checking visited[i] == -1, you would check visited[i] != sentinel.
LINK -> https://codeforces.com/blog/entry/48417?#comment-363271









*/