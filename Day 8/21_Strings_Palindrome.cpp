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
    
    for(int i = 0; i<n/2; i++) {
        if(str[i] != str[n-i-1]){
            cout<<"Not a Palindrome";
            return 0;
        }
    }
    
    cout<<"Palindrome";
    return 0;
}
