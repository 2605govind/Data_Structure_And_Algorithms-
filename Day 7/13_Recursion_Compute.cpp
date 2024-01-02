#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int power(int a, int n) {
    if(n == 1) return a;
    
    return a * power(a,n-1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int a, n;
    cin>>a>>n;
    
    int ans = power(a,n);
    
    cout<<"The value of "<<a<<" power "<<n<<" is "<<ans;
    return 0;
}
