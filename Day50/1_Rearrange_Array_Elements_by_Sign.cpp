#include<iostream>
#include<vector>
using namespace std;

// Naive solution
class Solution_1 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for(auto x : nums) {
            (x < 0)? negative.push_back(x) : positive.push_back(x);
        }

        vector<int> ans;
        int i = 0, j = 0, n = positive.size(), m = negative.size();

        while(i < n && j < m) {
            ans.push_back(positive[i++]);
            ans.push_back(negative[j++]);
        }

        while(i < n) {
            ans.push_back(positive[i++]);
        }

        while(j < m) {
            ans.push_back(negative[j++]);
        }

        return ans;
    }
};

// Optimize solution
class Solution_2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int i = 0, j = 1;

        for(auto x : nums) {
            if(x < 0) {
                ans[j] = x;
                j += 2;
            }else {
                ans[i] = x;
                i += 2;
            }  
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};

    // Solution_1 s1;
    // vector<int> ans = s1.rearrangeArray(nums);

    Solution_2 s2;
    vector<int> ans = s2.rearrangeArray(nums);
    
    // Print
    for(auto x : ans) {
        cout<<x<<" ";
    }
}
