#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n&1) {
            return 0;
        }

        unordered_map<int,int> mp;

        for(int i = 0; i < n; ++i) {
            mp[nums[i]]++;
        }

        for(auto x : mp) {
            if(x.second&1) {
                return 0;
            }
        }
        return 1;
    }
};

int main(){
    vector<int> nums = {2,3,2,3,2,3};
    
    Solution s1;
    if(s1.divideArray(nums)){
        cout<<"true";
    }else{
        cout<<"false";

    }
}
