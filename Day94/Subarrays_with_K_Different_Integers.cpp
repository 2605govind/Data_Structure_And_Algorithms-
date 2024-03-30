#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int one = subarray_with_atmost_k(nums, k);
        int two = subarray_with_atmost_k(nums, k-1);

        return one - two;
    }

    int subarray_with_atmost_k(vector<int> &nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0, j = 0, ans = 0;

        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() > k) {
                mp[nums[i]]--;

                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            ans += j - i + 1;
            j++;
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,1,2,3};
    int k = 2;

    Solution s;
    cout<<s.subarraysWithKDistinct(nums,k);
}


/*
Input: nums = [1,2,1,2,3], k = 2
Output: 7

*/