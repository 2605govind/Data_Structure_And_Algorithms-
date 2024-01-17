//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void allPer(int n, vector<int> &arr, vector<int> &ds, set< vector<int> > &ans, vector<bool> &visi){
        if(n == ds.size()){
            ans.insert(ds);
            return;
        }
        
        for(int i = 0; i<n; i++){
            if(!visi[i]){
                visi[i] = true;
                ds.push_back(arr[i]);
                allPer(n, arr, ds, ans,visi);
                ds.pop_back();
                visi[i] = false;
            }
        }
    }
    
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> ans;
        vector<int> ds;
        vector<bool> visi(n,false);
        
        allPer(n, arr, ds, ans,visi);
        
        vector<vector<int>> v;
        for(auto x : ans){
            v.push_back(x);
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends