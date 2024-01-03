#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<string> vec;
    
    while(1) {
        string str;
        cin>>str;
        
        if(str[0] == '#'){
            break;
        }
        vec.push_back(str);
    }
    
    int n = vec.size();
    
    cout<<vec[0]<<endl;
    char ch = vec[0][vec[0].size()-1];
    
    for(int i = 1; i<n; i++) {
        string str = vec[i];
        
        if(ch == str[0]) {
            ch = str[str.size()-1];
            cout<<str<<endl;
        }
        
    }
    return 0;
}
