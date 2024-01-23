#include <iostream>
using namespace std;

int GCD(int a, int b){

    if(a%b == 0){
        return b;
    }
    if(b%a == 0){
        return a;
    }
    if(a == b){
        return b;
    }
    if(a > b){
        return GCD(a%b,b);
    }else{
        return GCD(a,b%a);
    }
}

int main(){
    cout<<GCD(36,24);;
    return 0;
}