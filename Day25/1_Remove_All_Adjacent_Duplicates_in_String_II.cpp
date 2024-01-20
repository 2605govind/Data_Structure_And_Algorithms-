#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector< pair<int,int> > st;
        int n = s.size(), i = 0;

        while(i < n) {
            if(st.empty() || st.back().first != s[i]) {
                st.push_back({s[i], 1});

            }else {
                st.back().second++;

                if(st.back().second == k) {
                    st.pop_back();
                }
            }

            i++;
        }

        string ans;
        for(auto x : st) {
            while(x.second--) {
                ans.push_back(x.first);
            }
        }        

        return ans;
    }
};

int main(){
    Solution s;
    string str = "deeedbbcccbdaa";
    int k = 3;

    string ans = s.removeDuplicates(str, k);
    cout<<ans;
}
