//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        int mx = INT_MIN;
        for(auto x : a) {
            mx = max(mx, x);
        }
        
        vector<int> myHash(mx+1, 0);
            
        vector<int> ans;
        
        for(auto x : b) {
            if(x <= mx)
            myHash[x]++;
        }
        
        for(int i = 1; i < myHash.size(); i++) {
            myHash[i] = myHash[i-1] + myHash[i];
        }
        
        for(auto x : query) {
            ans.push_back(myHash[a[x]]);
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
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends