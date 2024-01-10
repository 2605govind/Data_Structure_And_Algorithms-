#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> nextGreater;
        stack<int> s;

        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums2[i]){
                s.pop();
            }

            if(s.empty()) {
                nextGreater[nums2[i]] = -1;
            }else {
                nextGreater[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        vector<int> ans;

        for(auto x : nums1) {
            ans.push_back(nextGreater[x]);
        }

        return ans;
    }
};


int main(){
    
}
