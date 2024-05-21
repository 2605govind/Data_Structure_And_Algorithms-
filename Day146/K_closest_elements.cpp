//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> v, int n, int k, int x) {
        int j=upper_bound(v.begin(), v.end(), x)- v.begin();
        int i=lower_bound(v.begin(), v.end(), x)- v.begin();
        i--;
        vector<int> ans;
        
        while(k--) {
            int a=INT_MAX, b=INT_MAX;
            if(i>=0) a=x-v[i];
            if(j<n) b=v[j]-x;
            
            if(b<=a) {
                ans.push_back(v[j]);
                j++;
            }
            else {
                ans.push_back(v[i]);
                i--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends