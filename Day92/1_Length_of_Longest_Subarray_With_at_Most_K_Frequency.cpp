#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();

        int i = 0, j = 0, ans = 0;
        while(j < n) {
            mp[nums[j]]++;

            if(mp[nums[j]] > k) {
                while(nums[i] != nums[j]) {
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};


int main(){
    vector<int> nums = {1,2,3,1,2,3,1,2};
    int k = 2;

    Solution s;
    cout<<s. maxSubarrayLength(nums, k);
}

/*
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6

https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

*/
