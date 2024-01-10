#include<iostream>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mps;
        int ans = 0;

        for(auto x : s) mps[x]++;
        for(auto x : t) mps[x]--;
        
        for(auto x : mps) (x.second > 0) ? ans += x.second : 0;
        return ans;
    }
};

int main(){
    
}
