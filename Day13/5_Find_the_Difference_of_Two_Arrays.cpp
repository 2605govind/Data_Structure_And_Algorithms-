#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public: // Time Complexity O(N + M) & SC O(N + M) 
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;

        // Inserting element in set for constant time searching
        for(auto it : nums1){
            s1.insert(it);
        }

        for(auto it : nums2){
            s2.insert(it);
        }

        // For storing resulting value in this
        vector<int> ans1;
        vector<int> ans2;

        // Iterate nums1 and searching in set2 
        for(auto it : nums1){

            // If element is not present the goto inside
            if(s2.count(it) == 0) {
                ans1.push_back(it);

                // Using this (it) element repeat the not should be going to again in ans so that we insert in set2
                s2.insert(it);
            }
        }

        for(auto it : nums2){
            if(s1.count(it) == 0) {
                ans2.push_back(it);
                s1.insert(it);
            }
        }

        return {ans1, ans2};
    }
};

int main(){
    vector<int> nums1 = {1,2,3,3};
    vector<int> nums2 = {1,1,2,2};

    Solution s;
    vector<vector<int>> ans = s.findDifference(nums1,nums2);
    
    for(int i = 0; i<ans[0].size(); i++) {
        cout<<ans[0][i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i<ans[1].size(); i++) {
        cout<<ans[1][i]<<" ";
    }
    
}
