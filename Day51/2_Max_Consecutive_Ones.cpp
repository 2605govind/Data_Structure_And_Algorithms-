#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Here "res" store max consecutive ones and "count" store number of once
        int res = 0, count = 0;
        
        // Iterate element one by one
        for(int x : nums) {
            count++;
            // If we get o then count become zero
            if(x == 0) count = 0;

            // if count is max then assign in res 
            res = max(res, count);
        }

        return res;
    }
};

int main(){
    vector<int> nums = {1,1,0,1,1,1};

    Solution s;
    cout<<s.findMaxConsecutiveOnes(nums);
}
