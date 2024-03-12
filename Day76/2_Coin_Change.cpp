#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int count(int coins[], int n, int sum) {
        vector<vector<long long int>> t(n+1, vector<long long int>(sum+1, 0));
        
        for(int i = 0; i < n+1; i++) {
            t[i][0] = 1;
        }
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < sum+1; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                }else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][sum];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}

/*

    https://www.geeksforgeeks.org/problems/coin-change2448/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

    Input:
    N = 3, sum = 4
    coins = {1,2,3}
    Output: 4

    
*/