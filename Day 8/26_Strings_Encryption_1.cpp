#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str;
    cin>>str;
    
    int n = str.size();
    for(int i = 0; i<n-1; i += 2) {
        swap(str[i], str[i+1]);
    }
    cout<<str;
    return 0;
}
