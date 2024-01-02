#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int fib(int n) {
    if(n <= 1) return n;
    
    return fib(n-1) + fib(n-2);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int a;
    cin>>a;
    
    int ans = fib(a-1);
    
    cout<<"The term "<<a<<" in the Fibonacci series is "<<ans;
    return 0;
}
