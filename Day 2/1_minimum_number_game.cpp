#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 1; i<n; i += 2) {
            swap(nums[i-1], nums[i]);
        }

        return nums;
    }
};

void print(vector<int> &num) {
    int n = num.size();
    for(int i=0; i<n; i++) {
        cout<<num[i];
    }
    cout<<"\n";
}

int main(){
    vector<int> nums = {4,2,7,3,8,5};
    print(nums);

    Solution s1;
    nums = s1.numberGame(nums);

    print(nums);
}
