#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void countTriplate(vector<int> nums) {
        int count = 0;

        int n = nums.size();
        for(int i = 0; i< n-1; i++) {
            int val = nums[i];
            for(int k = i+1; k < n; k++) {
                val = val ^ nums[k];

                if(val == 0) {
                    count += (k-i);
                }
            }
        }

        cout<<"Triplate Count is "<<count;
    }
};

int main(){
    vector<int> nums = {1,2,3};

    Solution s;
    s.countTriplate(nums);
}
