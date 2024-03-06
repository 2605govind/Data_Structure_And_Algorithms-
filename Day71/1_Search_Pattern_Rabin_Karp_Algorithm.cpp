#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        // Method for pattern searching
        vector<int> search(string pattern, string text) {
            vector<int> ans;
            string s;

            // Using two pointer approach
            int i = 0, j = 0;
            while(j < text.size()){
                s.push_back(text[j]);
                
                if((j-i+1) < pattern.size()){
                    j++;
                    
                } else {
                    if(s == pattern) {
                        ans.push_back(i+1);
                    }
                    i++;
                    j++;
                    s.erase(s.begin());
                }
            }
            
            return ans;
        }
     
};

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
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}