#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int cutRod(int price[], int n) {
        int length[n];
        for(int i = 0; i < n; i++) {
            length[i] = i+1; 
        }
        
        vector<vector<int>> t(n+1, vector<int>(n+1, 0));
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(length[i-1] <= j) {
                    t[i][j] = max(price[i-1]+ t[i][j-length[i-1]], t[i-1][j]);
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][n];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}

/*
    https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
    
    Input:
    N = 8
    Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
    Output:
    22
*/
