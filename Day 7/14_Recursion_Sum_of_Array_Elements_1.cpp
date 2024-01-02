#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sumArray(vector<int> num) {
    int sum = 0;
    for(auto x : num) {
        sum += x;
    }
    
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    cin>>n;
    
    int val;
    vector<int> array;
    for(int i = 0; i < n; i++) {
        cin>>val;
        array.push_back(val);
    }
    
    int sum = sumArray(array);
    
    cout<<sum;
    return 0;
}
