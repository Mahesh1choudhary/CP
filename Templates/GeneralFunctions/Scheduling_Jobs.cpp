#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
using namespace std;


// LINK -> https://cp-algorithms.com/schedules/schedule_one_machine.html
// SCHEDULING JOB ON ONE MACHINE
/*
n jobs , i th job can be processed in ti time, but for a wait of t seconds before processing will have penalty of fi(t)
find optimal order with minimal total penalty
*/

// CASE 1 -> Linear penalty functions => fi(t) = ci*t;
//case of fi(t)= ci*t+ di can also be handled the same, as constant terms have constant contribution, so them all , remove from equations and add to the final answer
// using swaping/permutation method, optimal condition is sort by ci/ti in non ascending order


// CASE 2 -> exponential penalty function => fi(t)= ci*e^(a*t)
// Again using swapping/permutation method, optimal condition is to sort by (1-e^(a*ti))/ci in non ascending order


// CASE 3 ->  Identical monotone increasing function
// arrange by non-descending processing time ti


// Livshits - Kladov theorem -> Permuatation method is applicable for only above mentioned three cases -> fi(t) = ci*t+di, fi(t)= ci*e^(a*t)+di, fi(t)=c*(t), fi(t)=phi(t) where phi is a monotone increasing function
// In all other cases, method cannot be applied






// SCHEDULING JOB ON TWO MACHINES -> LINK -> https://cp-algorithms.com/schedules/schedule_two_machines.html
//  Every item must first be processed on the first machine, and afterwards on the second one. The i-th job takes ai time on the first machine, and bi time on the second machine. Find the optimal order of the jobs, so that the final processing time is the minimum possible.






