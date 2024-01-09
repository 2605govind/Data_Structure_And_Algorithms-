#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappearedNum;

        for(auto x : nums) {
            int val = abs(x);
            nums[val-1] = -abs(nums[val-1]); 
        }

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                disappearedNum.push_back(i+1);
            }
        }

        return disappearedNum;
    }
};

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};

    Solution s;
    vector<int> ans = s.findDisappearedNumbers(nums);
    for(auto x : ans) {
        cout<<x<<" ";
    }
}
