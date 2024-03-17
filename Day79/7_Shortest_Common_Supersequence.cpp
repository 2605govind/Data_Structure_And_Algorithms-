#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(str1[i-1] == str2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }else {
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        
        string s;

        int i = m, j = n;

        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                s.push_back(str1[i-1]);
                i--, j--;
            }else {
                if(t[i-1][j] > t[i][j-1]) {
                    s.push_back(str1[i-1]);
                    i--;
                }else {
                    s.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        while(i > 0) {
            s.push_back(str1[i-1]);
            i--;
        }

        while(j > 0) {
            s.push_back(str2[j-1]);
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};

int main(){
    string str1 = "abac", str2 = "cab";

    Solution ob;
    cout<<ob.shortestCommonSupersequence(str1, str2);
}

/*
    https://leetcode.com/problems/shortest-common-supersequence/description/
*/