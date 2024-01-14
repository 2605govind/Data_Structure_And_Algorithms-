//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    string makeString(vector<int> &num){
        string ans;
        for(auto x : num) {
            ans.push_back(x + '0');
        }
        
        return ans;
    }
    
    public:
    vector<int> repeatedRows(vector<vector<int>> &mat, int M, int N) 
    { 
        unordered_set<string> uset;
        vector<int> ans;
        
        for(int i = 0; i<mat.size(); i++) {
            string str = makeString(mat[i]);
            if(!uset.count(str)){
                uset.insert(str);
            }else{
                ans.push_back(i);
            }
        }
        
        return ans;
    } 
    
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends