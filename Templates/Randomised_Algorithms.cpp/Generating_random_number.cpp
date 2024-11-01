


// do not used fixed seed- as it increases chances of hack
srand(40);  //-> do not use this

srand(time(NULL));  // -> can use this
// or
srand(chrono::steady_clock::now().time_since_epoch().count()); // This is the best

// fixed seed can be used for own testing for deterministic answer, but do not use in contest

// rand in codeforces can generate uptonumber upto 30000 (32767 exact). So if want to use random number from 1 to n, we can use mt19937;
// one way is as follows
long long my_rand(){
    long long a = rand();
    long long b = rand();
    return a*(RAND_MAX+1)+b;
}
// rand() -> generates number from [0,RAND_MAX]
// complexity of rand() is O(1) -> both time and space
// LINK -> https://codeforces.com/blog/entry/61587
// LINK -> https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/

// without srand rand assumes srand(1);
// constant seed generates same sequence of numbers in each run

// with srand(time(0)), rand() will generate different sequence of numbers in each run





ALWAYS USE THIS // LINK -> https://codeforces.com/blog/entry/61587
//  EVEN USING RAND IS NOT GOOD BECAUSE ITS VALUE IS LIMITED TO 32767, SO INSTEAD OF IT USE mt19937 for 32 bit numbers and mt19937_64 for 64 bit numbers

mt19937 rng(time(NULL));
// or
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int r = rng();
