#include<bits/stdc++.h>
using namespace std;

void maxArea(vector<int>& nums){
    int n = nums.size();
    int s=0;
    int e=n-1;
    int max_area = -1;

    while (s < e)
    {
        int height = min(nums[s], nums[e]);
        int width = abs(e-s);
        cout<<height<<" "<<width<<endl;
        max_area = max(max_area , height*width);

        if(nums[s] > nums[e]){
            e--;
        }else if(nums[s] < nums[e]){
            s++;
        }else{
            s++;
            e--;
        }
    }

    cout<<max_area;
    
}

int main(){
    vector<int> vec{1,8,6,1,5,4,8,3,7};
    maxArea(vec);
}
