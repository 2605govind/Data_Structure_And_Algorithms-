#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {

        int ans = 0;
        for(int i=0; i<32; i++) {

            int n = nums.size();
            int count = 0;
            for(int j=0; j<n; j++) {
                if(nums[j] & 1<<i) {
                    count++;
                }
            }

            if(count >= k) {
                ans = ans | 1<<i;
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {7,12,9,8,9,15};
    int k = 4;

    Solution s1;

    cout<<s1.findKOr(nums, k);
}
