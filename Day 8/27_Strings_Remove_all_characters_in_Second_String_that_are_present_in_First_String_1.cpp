#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str1;
    string str2;
    
    cin>>str1;
    cin>>str2;
    
    unordered_map<char,int> mp;
    
    int n = str2.size();
    for(int i = 0; i < n; i++) {
        mp[str2[i]]++;
    }
    
    int m = str1.size();
    for(int i = 0; i < m; i++) {
        mp[str1[i]]--;
    }
    
    string ans;
    for(int i = 0; i < n; i++) {
        if(mp[str2[i]] > 0) {
            ans.push_back(str2[i]);
            mp[str2[i]]--;
        }
    }
    
    cout<<ans;
    return 0;
}
