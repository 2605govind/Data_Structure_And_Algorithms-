#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // Initialize size of array
        int n = height.size();

        // Store trap rain water in "res"
        int res = 0;

        // Storing right most and left most height
        int maxLeft = 0, maxRight = 0;

        // Using 2-pointer approach
        int i = 0, j = n - 1;

        while(i <= j) {
            // If ith height is smallest and equle to jth height then
            if(height[i] <= height[j]) {

                // If height is small form maxLeft then assign
                if(maxLeft <= height[i]) {
                    maxLeft = height[i];
                // Else add res difference between maxLeft - height[i]:it refer trap water
                }else {
                    res += maxLeft - height[i];
                }
                i++;

            // If ith height is greater then jth height then
            }else{

                // If height is small form maxRight then assign
                if(maxRight <= height[j]) {
                    maxRight = height[j];

                // Else add res difference between maxRight - height[j]:it refer trap water
                }else {
                    res += maxRight - height[j];
                }
                j--;
            }

        }

        return res;
    }
};

int main(){
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;
    cout<<s.trap(nums);
}
