#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(auto x : s) {
            mp[x]++;
        }

        vector<pair<int,char>> vec;

        for(auto x : mp) {
            vec.push_back({x.second, x.first});
        }

        sort(vec.begin(), vec.end());

        string ans;
        for(int i = vec.size()-1; i >= 0 ; i--) {
            while(vec[i].first--) {
                ans.push_back(vec[i].second);
            }
        }

        return ans;
    }
};

int main(){
    string str;
    cin>>str;

    Solution s;
    cout<<s.frequencySort(str);
}
