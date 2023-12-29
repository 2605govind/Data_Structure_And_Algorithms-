#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int currnum = pref[0];
        for(int i = 1 ; i < pref.size(); i++) {
            int num = currnum;
            currnum = pref[i];
            pref[i] = num ^ pref[i];
        }

        return pref;
    }
};

int main(){
    vector<int> nums = {5,2,0,3,1};

    Solution s;
    s.findArray(nums);

    for(auto x : nums) {
        cout<<x<<" ";
    }
}
