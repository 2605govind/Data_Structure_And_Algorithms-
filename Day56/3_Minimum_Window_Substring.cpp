#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        //Edge case
        if(s.size() < t.size()) return "";

        // Storing count of characters of string t
        unordered_map<char,int> mp;
        for(auto x : t) {
            mp[x]++;
        }

        // Using sliding widnow technique
        int i = 0, j = 0, n = s.size(), ans = n, count = mp.size();
        int start = -1, end = -1;

        while(j < n) {
            // Calculation
            // If jth character present in map then decrease
            if(mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                // If charater occurence is zero then decrease count by 1
                if(mp[s[j]] == 0) {
                    count--;
                }
            }

            // If count is greate then zero then remove character count from map till count is not zero
            if(count > 0 ){
                j++;

            // If count is zero mean we have a substring which is setisfy then condition
            }else if(count == 0) {
                // From ith side remove character from substring based on condition
                while(count == 0) {
                    // If character is present in map then increase
                    if(mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        // If character occurenc is 1 then increase count by 1
                        if(mp[s[i]] == 1) {
                            count++;
                        }
                    }

                    // Check minimum substring and sotring first and end index
                    if(ans >= (j-i+1)) {
                        start = i;
                        end = j;
                        ans = (j-i+1);     
                    }
                    i++;
                }
                j++;
            }
        }

        // If substring is not get then return empty string
        if(start == -1 && end == -1) return "";

        // Now generate string usign starting and ending index
        string str;
        while(start <= end) {
            str.push_back(s[start++]);
        }

        // Return minimum window substring
        return str;
    }
};

int main(){
    string s = "ADOBECODEBANC", t = "ABC";

    Solution obj;
    cout<<obj.minWindow(s, t);
}
