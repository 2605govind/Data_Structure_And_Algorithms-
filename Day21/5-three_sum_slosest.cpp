#include<bits/stdc++.h>
using namespace std;

int twoSum(vector<int>& nums, int s, int e, int n1){
    int result = INT_MAX;
    while (s<e)
    {
        int sum = n1 + nums[s] + nums[e];
        
        if(sum < result){
            result = sum;
        }
        s++;
        e--;
    }
    return result;
}

int threeSumClosest(vector<int>& nums, int target){
    int n = nums.size();
    int result = 100000;
    int closest_sum;

    // sort given array
    sort(nums.begin(), nums.end());

    for(int i=0; i<n-2; i++){
        int sum = twoSum(nums, i+1, n-1, nums[i]);
        int min = abs(target - sum);
        // cout<<min<<"  ";
        if(min < result){
            result = min;
            closest_sum = sum;
        }
    }
    return closest_sum;
}

int main(){
    vector<int> nums{-4,-1,1,2};
    cout<<threeSumClosest(nums, 1);
}
