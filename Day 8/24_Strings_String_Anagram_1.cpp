#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s1, s2;
    cin>>s1;
    cin>>s2;
    
    int hash[26] = {0};
    int n = s1.size();
    for(int i = 0; i<n; i++) {
        hash[s1[i]-'a']++;
        hash[s2[i]-'a']++;
    }
    
    for(int i = 0; i<n; i++) {
        if(hash[s1[i] - 'a'] != 2) {
            cout<<"Not Anagram";
            return 0;
        }
    }
    
    cout<<"Anagram";
    
    return 0;
}
