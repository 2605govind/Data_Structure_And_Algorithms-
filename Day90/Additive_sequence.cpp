//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    bool isAdditiveSequence(string s) {
        // Your code here
        int n = s.size();
        int i=0, num1 = 0, num2 = 0, num3 = 0;
        while(i < n)
        {
            int f = 0;
            for(; i<n; i++)
            {
                num1 = num1*10 + (s[i] - '0');
                int num2 = 0;
                for(int j=i+1; j<n; j++)
                {
                    num2  = num2*10 + (s[j] - '0');
                    int num3 = 0;
                    for(int k = j+1; k<n; k++)
                    {
                        num3 = num3*10 + (s[k] - '0');
                        if(num1 + num2 == num3 && k == n-1) return 1;
                        if(num1 + num2 == num3)  
                        {
                            f = 1;
                            num1 = num2 = num3 = 0;
                            break;
                        }
                       
                    }
                    if(f) break;
                    
                }
                if(f) break;
            }
            if(!f) return 0;
            i++;
           
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends