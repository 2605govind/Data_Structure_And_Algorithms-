//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) {
        vector<int> ans;
        int n = mat.size();
        
        for(int k = 0; k < n; k++) {
            int i = 0;
            int j = k;
            
            while(i <= k) {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
        }
        
        for(int k = 1; k < n; k++) {
            int i = k;
            int j = n-1;
            
            while(j >= k) {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
  
    Solution ob;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> vec = ob.antiDiagonalPattern(mat);

    for(auto x : vec) {
        cout<<x<<" ";
    } 
    /*
    3
    1 2 3 4 5 6 7 8 9
    */
}
