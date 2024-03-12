#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int minCoins(vector<int> &coins, int M, int V) { 
        vector<vector<int>> t(M+1, vector<int>(V+1, 0));
        
        for(int j = 0; j < V+1; j++) {
            t[0][j] = INT_MAX - 1;
            
            if(j % coins[0] == 0) {
                t[1][j] = j / coins[0];
            }else {
                t[1][j] = 0;
            }
        }
        
        for(int i = 1; i < M+1; i++) {
            for(int j = 1; j < V+1; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
                }else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        if(t[M][V] == INT_MAX - 1) {
            return -1;
        }else {
            return t[M][V];
        }
	} 
	  
};


int main() {
   	int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

/*
    https://www.geeksforgeeks.org/problems/number-of-coins1824/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

    Input: V = 30, M = 3, coins[] = {25, 10, 5}
    Output: 2
*/