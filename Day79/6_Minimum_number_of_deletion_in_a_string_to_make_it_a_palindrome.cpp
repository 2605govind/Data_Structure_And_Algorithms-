#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
    return 0;
}

int minDeletions(string str, int n) { 
    string res_str = str;
    reverse(res_str.begin(), res_str.end());
    
    vector<vector<int>> t(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(str[i-1] == res_str[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }else {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    
    return n - t[n][n];
} 

/*
    https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

    Input: n = 7, str = "aebcbda"
    Output: 2
*/