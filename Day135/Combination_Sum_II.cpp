//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    
    void solve(vector<int> &arr, int n, int k, vector<int> &v, int i, set<vector<int>> &s) {
        
        if(k < 0) return;
        
        if(k == 0 or i == n) {
            if(k == 0) {
                s.insert(v);
            }
            return;
        }
        
        v.push_back(arr[i]);
        solve(arr, n, k - arr[i], v, i+1, s);
        v.pop_back();
        solve(arr, n, k, v, i+1, s);
    }
    
public:
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {   
        sort(arr.begin(), arr.end());
        vector<int> v;
        set<vector<int>> s;
        solve(arr, n, k, v, 0, s);
        
        
        vector<vector<int>> ans;
        for(auto &x : s) {
            ans.push_back(x);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends