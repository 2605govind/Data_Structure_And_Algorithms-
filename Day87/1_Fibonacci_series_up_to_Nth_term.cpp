//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007;
class Solution {
  public:
    vector<int> Series(int n) {
        vector<int> ans(n+1, -1);
        ans[0] = 0;
        ans[1] = ans[2] = 1;
        
        for(int i = 3; i <= n; i++) {
            ans[i] = (ans[i-1] + ans[i-2]) % mod;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends