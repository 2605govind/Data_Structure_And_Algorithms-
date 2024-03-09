#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Method for finding nth character
    char nthCharacter(string s, int r, int n) {
        // Iterate r number of times
        for(int i = 1; i <= r; i++) {
            // Every generated string store in "ans" variable
            string ans = "";
            
            // Iterate currence string and generate string according to given condition
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == '1') {
                    ans = ans + "10";
                }else {
                    ans = ans + "01";
                }
            }
            
            // smaller then n substring store in s
            s = ans.substr(0, n+1);
        }

        return s[n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
