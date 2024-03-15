#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestPalinSubseq(string A) {
        string str1 = A;
        string str2 = A; // Copy A to str2
        
        reverse(str2.begin(), str2.end()); // Reverse str2

        // Find LCS
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }

        return t[m][n];
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}

/*
    
    https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

    Input:
    S = "bbabcbcab"
    Output: 7
*/