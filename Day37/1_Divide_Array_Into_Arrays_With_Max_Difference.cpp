#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i+2 < n; i++) {
            if(i%3 == 0) {
                if(nums[i+2] - nums[i] <= k){
                    ans.push_back({nums[i], nums[i+1], nums[i+2]});
                }else {
                    return {};
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;

    Solution s;
    vector<vector<int>> ans = s.divideArray(nums,k);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
