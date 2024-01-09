//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector <int> search(string pat, string txt)
        {
            //code hee.
            string s = pat + "#" + txt;
            
            int n = s.size();
            vector<int> track(n);
            
            int j = 1;
            int i = 0;
            
            while(j < n) {
                if(s[i] == s[j]) {
                    i++;
                    track[j] = i;
                    j++;
                }else {
                    if(i-1 < 0) {
                        j++;
                    }else {
                        i = track[i-1];
                    }
                }
            }
            
            int m = pat.size();
            vector <int>  ans;
        
            for(int j=1;j<track.size();j++){
                if(track[j]==m){
                    ans.push_back(j-2*m+1);
                }
            }
            
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends