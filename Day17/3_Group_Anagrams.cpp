#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> strs) {
        int n = strs.size();
        // Edge case if string has only one string 
        if(n == 1) return {{strs[0]}}; 
    
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto x : strs){
            string word = x;
            sort(word.begin(), word.end());
            if(mp.count(word)) {
                mp[word].push_back(x);
            }else{
                mp[word] = {x};
            }
        }

        for(auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }


};

int main(){
    
}
