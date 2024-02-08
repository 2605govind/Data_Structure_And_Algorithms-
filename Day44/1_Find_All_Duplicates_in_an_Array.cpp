#include<iostream>
#include<vector>
using namespace std;

// TC = O(N) & SC (1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(nums[abs(nums[i]) - 1] < 0) {
                ans.push_back(abs(nums[i]));
            }else {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};

    Solution s;
    vector<int> ans = s.findDuplicates(nums);

    for(auto x : ans) {
        cout<<x<<" ";
    }
}
