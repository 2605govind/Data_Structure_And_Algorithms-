#include<iostream>
using namespace std;

void print(short n) {
    while(n) {
        bool digit = n&1;
        cout<<digit;
        n = n>>1;
    }
    cout<<endl;
}
int main(){
    unsigned short var = 32769;
    print(var);
}
