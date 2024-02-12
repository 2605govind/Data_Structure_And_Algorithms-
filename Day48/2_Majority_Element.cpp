#include<iostream>
#include<vector>
using namespace std;

// Time complexity O(N) and Space complexity O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int occ = 1;
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            if(occ == 0) {
                ans = nums[i];
            }

            if(ans == nums[i]) {
                occ++;
            }else {
                occ--;
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};

    Solution s;
    cout<<s.majorityElement(nums);
}
