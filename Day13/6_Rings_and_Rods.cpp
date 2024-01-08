#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        // If righs has not enugh 3 color then return 0
        if(rings.size() <= 4) return 0;

        // colorCode store color existance in rods
        vector<vector<int>> colorCode(10,vector<int>(3));

        // It help colorCode 2d array for giving index 
        unordered_map<char,int> mp;
        mp['R'] = 0;
        mp['G'] = 1; 
        mp['B'] = 2; 

        int n = rings.size();

        for(int i = 0; i<n; i += 2) {
            // Just store existance of color in rods 0 to 9 through it
            colorCode[rings[i+1] - '0'][mp[rings[i]]] = 1;
        }

        // Now count variable count all rods has 3 color (R G B)
        int count = 0;
        for(int i = 0; i < 10; i++) {
            int sum  = 0;
            for(int j = 0; j < 3; j++) {
                sum += colorCode[i][j];
                
            }
            if(sum == 3) {
                count++;
            }
        }

        return count;
    }
};

int main(){
    string str = "B0B6G0R6R0R6G9";

    Solution s;
    cout<<s.countPoints(str);
}
