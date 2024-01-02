#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int fac(int n) {
    if(n == 1) return n;
    
    return n * fac(n-1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int t;
    cin>>t;
    
    int ans = fac(t);
    
    cout<<"The factorial of "<<t<<" is "<<ans;
    return 0;
}
