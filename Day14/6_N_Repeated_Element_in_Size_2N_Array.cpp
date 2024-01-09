#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;

        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto x : mp){
            if(x.second >= n/2){
                return x.first;
            }
        }

        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,1,5,2,5,3,5,4};
    cout<< s.repeatedNTimes(nums);
}
