#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:    
    int longestCommonSubstr (string s1, string s2, int n, int m) {
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }else {
                    t[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
               ans = max(ans, t[i][j]);
            }
        }
        
        return ans;
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}

/*
    https://www.geeksforgeeks.org/problems/longest-common-substring1452/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


    Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
    Output: 4

*/