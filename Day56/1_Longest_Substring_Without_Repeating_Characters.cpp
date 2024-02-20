#include<iostream>
#include<unordered_map>
using namespace std;

class Solution_1 {
public:
    int lengthOfLongestSubstring(string s) {
        // Edge case
        if(s.size() <= 1) return s.size(); 
        // Storing occurence of charactor
        unordered_map<char, int> mp;

        // Using sliding window technique
        int i = 0, j = 0, n = s.size(), ans = -1;

        while(j < n) {
            // Increase charactor count
            mp[s[j]]++;

            // If charactor count is 1 it's mean it is unique charactor contains
            if(mp[s[j]] == 1) {
                // Find max substring
                ans = max(ans, (j - i + 1));
                j++;

            // if count is greate thne 1 it's mean sub string is not contain unique element
            }else if(mp[s[j]] > 1) {
                // Remove duplicate form substring
                while(mp[s[j]] != 1) {
                    mp[s[i]]--;
                    i++; 
                }
                j++;
            }
        }

        return ans;
    }
};

class Solution_2 {
public:
    int lengthOfLongestSubstring(string s) {
        // Edge case
        if(s.size() <= 1) return s.size(); 

        // Storing occurence of charactor
        unordered_map<char, int> mp;

        // Using sliding window technique
        int i = 0, j = 0, n = s.size(), ans = -1;

        while(j < n) {
            // Increase charactor count
            mp[s[j]]++;

            // If map size and substring lenght equal it's mean it is unique charactor contains
            if(mp.size() == (j - i + 1)) {
                // Find max substring
                ans = max(ans, (j - i + 1));
                j++;

            // if count is greate thne 1 it's mean sub string is not contain unique element
            }else if(mp.size() < (j - i + 1)) {
                // Remove duplicate form substring
                while(mp.size() < (j - i + 1)) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
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

int main(){
    string s = "abcabcbb";

    Solution_1 s1;

    cout<<s1.lengthOfLongestSubstring(s);
}
