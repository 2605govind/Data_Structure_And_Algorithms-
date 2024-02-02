#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int n = s.size();
        
        // Check given sring is feasible or not
        for(int i = 1; i < n; i++) {
            if(s[i] < '0' || s[i] > '9'){
                return -1;
            }
        }
        
        // If initially '-' and '0' then skip these
        int i = 0;
        while(s[i] == '0' || s[i] == '-') {
            i++;
        }
        
        int ans = 0, ten = 1;

        // Now converting string to number
        for(int j = n-1; j >= i; j--) {
            int digit = s[j] - '0';
            
            ans = ans + digit * ten;
            ten = ten * 10;
        }
        
        // If string contain initially '-' it mean value is nagative then return -ans
        if(s[0] == '-') {
            return -ans;
        }
        
        return ans;
        
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}

/*output:-
    2
    -242
    -242
    
    -ad324
    -1

*/