#include<iostream>
using namespace std;

int main(){

    // 1. first approach
    // TC = O(n) where n is given number
    // int num = 17;
    // for(int i = 2; i<num; i++){
    //     if(num % i == 0){
    //         cout<<"not prime";
    //         exit(0);
    //     }
    // }
    // cout<<"prime"; 
    // ----------------------------------------


    // 2. second approach
    // TC = O(n/2) = O(n) where n is given number
    // int num = 17;
    // for(int i = 2; i<=num/2; i++){
    //     if(num % i == 0){
    //         cout<<"not prime";
    //         exit(0);
    //     }
    // }
    // cout<<"prime";
    // ----------------------------------------


     // 3. third approach
    // TC = O(sqrt(n)) where n is given number

    bool flag = 0;
    int num = 17;
    for(int i = 2; i<=sqrt(num); i++){
        if(num % i == 0){
            flag = 1;
        }
    }
    if(flag)
        cout<<"not prime";
    else    
        cout<<"prime";
    // ----------------------------------------
}
