/*
As mentioned in Rollback_general.cpp->
In many data structures, the operation of "undo" on the last update can be implemented easily:
we can (usually) maintain a stack of the updates, where each update on the stack holds the memory cells it changed,
and their original values. To undo an operation, just revert all changes from the top update on the stack. To maintain good complexity,
we require the updates to operate in non-amortized time.


Here we have queue of updates and we want to add a new update or undo the oldest update still active
LINK 1 - https://codeforces.com/blog/entry/83467



*/