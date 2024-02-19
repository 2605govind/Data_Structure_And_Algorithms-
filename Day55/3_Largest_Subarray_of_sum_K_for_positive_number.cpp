#include<iostream>
#include<vector>
using namespace std;

// Method for finding largest subarray sum of positive numbers
int largestSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    // Using sliding window technique
    int i = 0, j = 0, sum = 0, maxLength = 0;

    while(j < n) {
        // Add ith element in sum
        sum = sum + nums[j];

        // If sum is grater then k then remove ith element from sum
        if(sum > k) {
            while(sum > k) {
                sum -= nums[i];
                i++;
            }
        }

        // If sum is equle to k then store max length of subarray
        if(sum == k) {
            maxLength = max(maxLength, (j - i + 1));
        }

        j += 1;
    }

    return maxLength;
}

int main(){
    vector<int> nums = {4, 1, 1, 1, 2 , 5};
    int k = 5;

    cout<<largestSubarraySum(nums, k);
}
