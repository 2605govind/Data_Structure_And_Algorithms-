#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = INT_MIN, count = 0;
        long long ans = 0;
        for(auto x : nums) {
            mx = max(mx, x);
        }

        for(int i = 0, j = 0; j < nums.size(); j++) {
            if(nums[j] == mx) {
                count++;
            }

            while(count >= k) {
                if(nums[i] == mx) {
                    count--;
                }
                i++;
                ans += nums.size() - j;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,2,3,3};
    int k = 2;

    Solution s;
    cout<<s.countSubarrays(nums, k);
}

/*

Input: nums = [1,3,2,3,3], k = 2
Output: 6

*/
