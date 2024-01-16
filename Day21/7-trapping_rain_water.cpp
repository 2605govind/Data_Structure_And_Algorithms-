#include<bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> nums){
    int n = nums.size();
    int totalTrapWater = 0;
    int peak_value = min(nums[0],nums[n-1]);

    for (int i = 1; i < n-1; i++)
    {
        int availableHeight = peak_value-nums[i];
        if(availableHeight >0){
            totalTrapWater += availableHeight;
        } 
    }

    return totalTrapWater;
    
}

int main(){
    // vector<int> height{4,2,0,3,2,5};
    // vector<int> height{4,0,6};
    vector<int> height{4,1,6};

    cout<<trappingRainWater(height);
}
