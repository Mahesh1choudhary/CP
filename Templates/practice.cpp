#include <iostream>
#include <thread>
#include <bits/stdc++.h>
using namespace std;

void func(int x){
    for(int i=0;i<=x;i++){
        cout<<i<<endl;
    }
}
void func2(int x){
    for(int i=x;i>=0;i--){
        cout<<i<<endl;
    }
}

int main(){
    std::thread t1(func,10);
    std::thread t2(func2,10);

    t1.join();
    t2.join();


    return 0;
}