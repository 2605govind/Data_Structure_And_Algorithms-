#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,int> people;

        // Map store in sorted way so we can insert height as well as names index
        int n = heights.size();
        for(int i = 0; i<n; i++) {
            people[heights[i]] = i;
        } 


        vector<string> ans(n);
        int i = n-1;
        // Iterate Map (people) and inserting in ans, end to begin becasue of Map is in ascending or and we want descending order so
        for(auto it : people){
            ans[i--] = (names[it.second]);
        }

        return ans;
    }
};

int main(){
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};

    Solution s;
    vector<string> ans = s.sortPeople(names, heights);

    for(auto x : ans) {
        cout<<x<<" ";
    }
    
}
