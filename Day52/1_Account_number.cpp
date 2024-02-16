#include<iostream>
#include <random>
using namespace std;

long long int generateAccountNumber() {
    long long int num;

    // Generate first digit but first digit is not be zero
    int val = rand()%10;
    num = num * 10 + (val == 0) ? val+1 : val;

    // Now generate 15 bigit and put in num
    for(int i= 0; i<15; i++) {
        num = num * 10 + rand() % 10;
    }

    return num;
}

bool checkValidOrNot(long long int num) {
    int odd = 0;
    int even = 0;

    for(int i = 1; i <= 16; i++) {
        int digit = num%10;
        num = num/10;

        if(i&1 == 1) {
            odd += digit*2;
        }else {
            even += digit;
        }
    }

    if((odd + even) % 10 == 0) {
        return 1;
    }else {
        return 0;
    }
}

int main(){

    for(int i = 0; i<100; i++) {
        long long int num = generateAccountNumber();

        cout<<num<<" ";
        if(checkValidOrNot(num)) {
            cout<<"This is currect number\n";
        }else {
            cout<<"This is not currect number\n";
        }
    }
}
