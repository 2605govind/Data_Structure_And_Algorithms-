//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int> arr(n, -1);
        
        for(int i = 0; i<n; i++) {
            if(gallery[i] == 0) {
                arr[i] = max(arr[i], i);
                continue;
            }
            
            if(gallery[i] != -1) {
                int k = i + gallery[i];
                int j = max(0 , i - gallery[i]);
                
                for(int sprink = j; sprink <= min(n,k); ++sprink){
                    arr[sprink] = max(arr[sprink], k);
                }
            }
        }
        
        int count = 0;
        int i = 0;
        
        while(i < n) {
            if(i == -1 || arr[i] == -1) {
                return -1;
            }
            
            count++;
            i = arr[i] + 1;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends