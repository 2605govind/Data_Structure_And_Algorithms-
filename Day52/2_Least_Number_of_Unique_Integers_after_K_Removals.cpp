#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        // Find occurence of elements
        for(auto x : arr) {
            mp[x]++;
        }

        // Storing accorence of unique number
        vector<int> nums;
        for(auto x : mp) {
            nums.push_back(x.second);
        }

        // sort in ascending order so that we remove k digits
        sort(nums.begin(), nums.end());

        // Initialize 
        int i, n = nums.size(), count = n;

        // Iterate one by one "nums"
        for(i = 0; i<n; i++) {
            // Remove smallest occurence 
            k -= nums[i];

            // If k remove perfect k digit then return
            if(k == 0) {
                return count-1;
            }

            // If k remove not perfect k digit then return
            if(k < 0) {
                return count;
            }

            // decrease unique number witch I remove using k 
            count--;
        }

        return count;
    }
};

int main(){
    vector<int> nums = {4,3,1,1,3,3,2};
    int k = 3;

    Solution s;

    cout<<s.findLeastNumOfUniqueInts(nums, k);
}
