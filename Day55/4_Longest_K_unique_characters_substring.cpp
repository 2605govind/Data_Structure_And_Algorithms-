#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // For stroing charactore counts
        unordered_map<char,int> mp;
        
        // Using sliding window technique
        int i = 0, j = 0, n = s.size(), ans = -1;
        
        while(j < n) {
            mp[s[j]]++;
            
            // If unique charactore is less then k 
            if(mp.size() < k) {
                j++;
                
            // If unique character is qnique to k then store mox window     
            }else if(mp.size() == k) {
                ans = max(ans, (j - i + 1));
                j++;
                
            // if unique is greater then k    
            }else if(mp.size() > k) {
                while(mp.size() > k) {
                    mp[s[i]]--;
                    
                    // If character has zero count then remove from unordered map
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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}


/*
    Input:
    1
    aabacbebebe
    3

    Output:
    7
*/