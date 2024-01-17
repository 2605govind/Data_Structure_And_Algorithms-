#include<iostream>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int sum = 0;

        int n = nums.size();
        for(int i = 0; i<n; i++) {
            sum += nums[i];

            int rem = sum % k;
            if(i != 0 && rem == 0){
                return true;
            }
            if(umap.find(rem) != umap.end()) {
                if((i - umap[rem]) >= 2)
                return true;
            }else{
                umap[rem] = i;
            }

        }

        return false;
    }
};

int main(){
    
}
