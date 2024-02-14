// Program : Squares of a sorted array
#include<iostream>
#include<vector>
using namespace std;

// Method class
class Solution {
public:
    // Method for square fo a sorted array and return sorted array using two pointer approach
    vector<int> sortedSquares(vector<int>& nums) {
        // Initialize
        int n = nums.size();
        vector<int> ans(n);

        // Take two pointer "left" ans "right" and assigns value 
        int left = 0, right = n-1, index = n-1;

        // Move left and right based on given criterial
        while(left <= right) {
            // Take square of left and right index value of array
            int s1 = nums[left] * nums[left]; 
            int s2 = nums[right] * nums[right]; 

            // If left index value suares s1 is smallest and eqale to right one then insert in "ans" array and decrement right
            if(s1 <= s2) {
                ans[index] = s2;
                right--, index--; 

            // Here assign left value to "ans" array and increament left
            }else {
                ans[index] = s1;
                left++, index--; 
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {-4,-1,0,3,10};

    Solution s;
    vector<int> sortedSquaresNums = s.sortedSquares(nums);

    for(auto x : sortedSquaresNums) {
        cout<<x<<" ";
    } 
}
