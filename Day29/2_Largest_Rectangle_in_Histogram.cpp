#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    vector<int> prevSmallest(vector<int> &nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.top()] >= nums[i]){
                s.pop();
            }

            ans[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> nextSmallest(vector<int> &nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] >= nums[i]){
                s.pop();
            }

            ans[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ps = prevSmallest(heights);
        vector<int> ns = nextSmallest(heights);

        int res = 0;

        int n = heights.size();
        for(int i = 0 ; i < n; i++) {
            int val = (ns[i] - ps[i] - 1) * heights[i];
            res = max(res, val);   
        }

        return res;
    }
};

int main(){
    vector<int> nums = {2,1,5,6,2,3};

    Solution s;
    cout<<s.largestRectangleArea(nums);
}
