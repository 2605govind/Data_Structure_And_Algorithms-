#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxValue(vector<int> num) {
    int m = num[0];
    for(auto x : num) {
        if(m < x) {
            m = x;
        }
    }
    
    return m;
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
    
    int mx = maxValue(array);
    
    cout<<"Maximum element in the array is "<<mx;
    return 0;
}
