#include<iostream>
using namespace std;

void print(int n) {
    if(!n)  return;
    int digit = n&1;
    print(n>>1);
    cout<<digit;
    
}

int main(){
    int n = 76;

    int onmast = (n << 3);
    int offmast = ~(n << 3);
    int togglemast = (n << 3);
    int checkmast = (n << 3);

    print(n);
    cout<<endl;
    print(n | onmast);
    cout<<endl;
    print(n & offmast);
    cout<<endl;
    print(n ^ togglemast);
    cout<<endl;
    print(n & checkmast);
}
