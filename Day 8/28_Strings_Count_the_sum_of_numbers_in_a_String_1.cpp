#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int makeNumber(vector<int> num) {
    int ans = 0;
    for(auto x: num) {
        ans = ans*10;
        ans = ans+x;
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string str;
    cin>>str;
    
    int n = str.size();
    int ans = 0;
    
    
    for(int i = 0; i < n; i++) {
        
        if(str[i] >= '0' && str[i] <= '9'){
            vector<int> num;
            int j = i;
            while(j < n) {
                
                if(str[i] >= '0' && str[i] <= '9'){
                    num.push_back(str[i]-'0');
                    i++;
                }else {
                    break;
                }
                
                j++;
            }
            
            ans += makeNumber(num);
        }
    }
    
    cout<<ans;
    return 0;
}
