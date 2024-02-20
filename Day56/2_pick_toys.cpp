// John is at a toy store help him pick maximum number of toys. He can only select in a continuous manner and he can select only two types of toys

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    // Method for finding maxmum subsring based on condition
    int findMaxToys(string s) {
        // Edge case
        if (s.size() <= 1) return s.size();

        // Storing count of toys
        unordered_map<char,int> mp;

        // Using sliding window technique
        int i = 0, j = 0, n = s.size(), ans = -1;

        while(j < n) {
            mp[s[j]]++;

            if(mp.size() < 2){
                j++;

            // If map size is two then store substring length 
            }else if(mp.size() == 2) {
                ans = max(ans, (j-i+1));
                j++;    

            // If map size is greate then 2 then remove toys from ith place
            }else if(mp.size() > 2) {
                // Remove
                while(mp.size() > 2) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }

        return ans;
    }
};

int main() {
    string s = "abaccab";

    Solution obj;
    cout<<obj.findMaxToys(s);
}
