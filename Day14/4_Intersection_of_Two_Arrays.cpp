#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset;

        // Sotring element one times
        for(auto x : nums1) {
            uset.insert(x);
        } 

        vector<int> ans;
        for(auto x : nums2) {
            // If nums2 elenent found in uset then insert into ans and then remove from uset
            if(uset.count(x)) {
                ans.push_back(x);
                uset.erase(x);
            }
        }

        return ans;
    }
};
int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    
    Solution s;
    vector<int> inter = s.intersection(nums1, nums2);

    for(auto x : inter) {
        cout<<x<<" ";
    }
}
