//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    // Method for printing 
    void solver(int one, int zero, int n, string op, vector<string> &v) {
        // leaf condition
        if(n == 0) {
            v.push_back(op);
            return;
        }
    
        // Every brance take 1
        solver(one+1, zero, n-1, op+'1', v);
    
        // If one is greater then 0 
        if(one > zero) {
            solver(one, zero+1, n-1, op+'0', v);
        }
    }
    
public:	
	vector<string> NBitBinary(int n){
	    vector<string> v;
        string op = "";
        int one = 0, zero = 0;
    
        solver(one, zero, n, op,v);
        
        return v;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends