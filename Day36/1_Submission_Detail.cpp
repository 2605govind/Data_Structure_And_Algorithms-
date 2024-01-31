#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    vector<int> nearestGreaterRight(vector<int> &nums) {
        int n = nums.size();
        stack<pair<int,int>> s; // Create an empty stack

        vector<int> ansIndex(n); // Storing nearest greater element index


        // Iterate from end
        for(int i = n-1; i >=0; i--) {
            // If current element is greater then stack top element then pop
            while(!s.empty() && nums[i] >= s.top().first) {
                s.pop();
            }

            // Storing nearest greater element index
            ansIndex[i] = (s.empty())? -1 : s.top().second;
       
            s.push({nums[i], i});
        }

        return ansIndex;
    }

public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nearestGIndex = nearestGreaterRight(temperatures);
        
        int n = nearestGIndex.size();
        for(int i = 0; i < n; i++) {
            if(nearestGIndex[i] == -1) {
                nearestGIndex[i] = 0;
            }else {
                nearestGIndex[i] -= i;
            }
        }
        
        return nearestGIndex;
    }
};


int main() {
    vector<int> temperatures  = {73,74,75,71,69,72,76,73};

    Solution s;
    vector<int> ans = s.dailyTemperatures(temperatures);

    for(auto x : temperatures) {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;
    for(auto x : ans) {
        cout<<x<<" ";
    }
    cout<<endl;
}

/*
    https://leetcode.com/problems/daily-temperatures/description/

    output:-
    73 74 75 71 69 72 76 73 

    1 1 4 2 1 1 0 0 
*/