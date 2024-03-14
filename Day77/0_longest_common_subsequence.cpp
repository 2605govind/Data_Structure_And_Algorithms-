#include<bits/stdc++.h>
using namespace std;

// Recursive way 
class Solution {
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2) {
        if(n == 0 || m == 0) {
            return 0;
        }
        
        if(s1[n-1] == s2[m-1]) {
            return 1 + lcs(n-1, m-1, s1, s2);
        }else {
            return max(lcs(n-1, m, s1, s2), lcs(n, m-1, s1, s2));
        }
    }
};

// Memoized - Bottom-up approach
class Solution_2 {
    int solve(int n, int m, string s1, string s2, vector<vector<int>> &t) {
        if(n == 0 || m == 0) {
            return 0;
        }
        
        if(t[n][m] != -1) {
            return t[n][m];
        }
        
        if(s1[n-1] == s2[m-1]) {
            return t[n][m] = 1 + solve(n-1, m-1, s1, s2, t);
            
        }else {
            return t[n][m] = max(solve(n-1, m, s1, s2, t), solve(n, m-1, s1, s2, t));
        }
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2) {
        vector<vector<int>> t(n+1, vector<int>(m+1, -1));
        
        return solve(n, m, s1, s2, t);
    }
};

int main() {
    int t,n,m;
    cin>>t;
    while(t--) {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

