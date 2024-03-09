#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;

        int i = 0, j = 0; 
        while(i < nums1.size() && j < nums2. size()) {
            if(nums1[i] == nums2[j]) {
                ans = min(ans, nums1[i]);
                i++;
                j++;
            }else if(nums1[i] < nums2[j]) {
                i++;
            }else{
                j++;
            }
        }

        if(ans == INT_MAX) return -1;

        return ans;
    }
};

int main(){
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4};

    Solution s;
    cout<<"Minimum common value is "<<s.getCommon(nums1, nums2);
}
