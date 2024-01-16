#include<bits/stdc++.h>
using namespace std;


// this is use for non sorted array
vector<int> towSum(vector<int> vec, int target){
    map< int , int > map_of_remaining_num;
    for (int i = 0; i < vec.size(); i++)
    {
        int remaining_num = target-vec[i];

        if(map_of_remaining_num.find(remaining_num) != map_of_remaining_num.end()){
            return {map_of_remaining_num[remaining_num], i};
        }

        map_of_remaining_num[vec[i]] = i;
    }
    return {};
}

// this is use for sorted array and return pos not index
vector<int> towSum2(vector<int> nums, int target){
    // this is two pointer approach
    int s = 0, e = nums.size()-1;

    while (s < e)
    {
        if(nums[s]+nums[e] == target)
            return {s+1, e+1};
        else if(nums[s]+nums[e] > target)
            e--;
        else
            s++;        
    }
    return {};
}
int main(){
    vector<int> v{2,5,11,15};
    vector<int> twosumSolv;
    twosumSolv = towSum2(v, 7);

    cout<<twosumSolv[0]<<" "<<twosumSolv[1];
}
