#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b != 0) {
        return gcd(b, a%b);
    } else {
        return a;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a, b;
    cin>>a>>b;
    
    cout<<gcd(a,b);
    return 0;
}
