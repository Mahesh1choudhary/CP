#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;


// we can use either cpp inbuilt function shuffle or our own shuffling function
// using rand is problematic as its highest value is 32767, so be careful while using it, if we need to generate higher values, use mt19937
// Rand genrates between [0, RAND_MAX], so be careful while using it
// METHOD 1 -> USING RANDOM_SHUFFLE ->  random_shuffle function swaps the value of each element with some other randomly picked element. When provided, the function gen determines which element is picked in every case. Otherwise, the function uses some unspecified source of randomness.

int randomfunct(int j){
    return rand()%j;
}

int main(){

    srand(time(0));
    vector<int> arr;

    // using built-in random generator
    random_shuffle(arr.begin(), arr.end());

    // using our own random selecting function
    random_shuffle(arr.begin(),arr.end(), randomfunct);

}

// METHOD 2 -> USING SHUFFLE ->  we can also use shuffle function




// METHOD 3 -> OUR OWN SHUFFLING FUNCTION -> this is same as random_shuffle with our own randomfunc defined
// LINK -> https://www.youtube.com/watch?v=GS2MxmorEzc (around time =10)

// this is not correct
for(int i=0;i<n;i++){
    int j=rand()%n;     // rand in [0,n-1]
    swap(arr[i],arr[j]);
}

// this is correct
for(int i=0;i<n;i++){
    int j=rand()%(i+1);  // rand in [0,i]
    swap(p[i],p[j]);
}





ALWAYS USE THIS
// DON'T USE RAND(), INSTEAD USE mt19937 for generating 32 bit numbers and mt19937_64 for generating 64 bit numbers
// Also don't use constant seed,
// LINK -> https://codeforces.com/blog/entry/61587

mt19937 rng(time(NULL));
// or
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    // this is best


int randomfunct(int j){
    return rng()%j;
}

int main(){

    
    vector<int> arr;

    // do not use using built-in random generator

    // using our own random selecting function
    random_shuffle(arr.begin(),arr.end(), randomfunct);

    // we can also use this 
    shuffle(arr.begin(), arr.end(), rng);
}




