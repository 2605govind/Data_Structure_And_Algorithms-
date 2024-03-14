#include<iostream>
#include<vector>
using namespace std;

// Code by Govind Chouhan
class Solution_1 {
    public:
    string findLCS(int n, int m,string &s1, string &s2){
        vector<vector<string>> t(n+1, vector<string>(m+1, ""));

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] =  t[i-1][j-1] + s1[i-1];
                }else {
                    if(t[i][j-1].size() < t[i-1][j].size()) {
                        t[i][j] = t[i-1][j];
                    }else {
                        t[i][j] = t[i][j-1];
                    }
                }
            }
        }
        return t[n][m];	
    }
};

class Solution_2 {
public:
    string longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(); 
        int m = s2.size();

        vector<vector<int>> t(n+1, vector<int>(m+1, 0));

	    for(int i = 1; i < n+1; i++) {
	    	for(int j = 1; j < m+1; j++) {
	    		if(s1[i-1] == s2[j-1]) {
	    			t[i][j] = t[i-1][j-1] + 1;
	    		}else {
	    			t[i][j] = max(t[i][j-1], t[i-1][j]);
	    		}
	    	}
	    }

        string s;
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                s = s1[i-1] + s;
                i--, j--;
            }else {
                if(t[i][j-1] > t[i-1][j]){
                    j--;
                }else{
                    i--;
                }
            }
        }
	    return s;
    }
};

int main(){
    string s1 = "acbcf";
    string s2 = "abcdaf";

    // Solution_1 obj;
    // cout<<obj.findLCS(s1.size(), s2.size(), s1, s2);

    Solution_2 obj;
    cout<<obj.longestCommonSubsequence(s1, s2);
}
