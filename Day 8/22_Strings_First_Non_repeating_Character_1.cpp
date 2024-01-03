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
    
    int hash[26] = {0};
    
    for(int i = 0; i<n; i++) {
       hash[str[i]-'a']++;
    }
    
    for(int i = 0; i<n; i++) {
       if(hash[str[i]-'a'] == 1) {
           cout<<str[i];
           return 0;
        }
    }
    
    cout<<"All the characters are repetitive";
    return 0;

}
