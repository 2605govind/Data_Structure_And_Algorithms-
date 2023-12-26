#include<iostream>
using namespace std;

// TC O(N) & SC(N)
class Solution_1 {

    // Function for finding numbers of ones from string
    int count(string s) {
        int n = s.size();
        bool flag = 1;
        int ones = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                ones++;
            }
        }

        return ones;
    }
    
public:
    int minOperations(string s) {
        string str1, str2;
        
        int n = s.size();
        bool flag = 1;

        // Make two alternating string str1 = "101010" and str2 = "010101"
        for(int i = 0; i < n; i++) {
            (flag == 1) ? str1.push_back('1') : str1.push_back('0');
            (flag == 1) ? str2.push_back('0') : str2.push_back('1');

            flag = !flag;
        }

        // Doing XOR operation through this loop
        for(int i = 0; i < n; i++) {
            (s[i] == '1' && str1[i] == '0' || s[i] == '0' && str1[i] == '1' ) ? str1[i] = '1' : str1[i] = '0'; 
            (s[i] == '1' && str2[i] == '0' || s[i] == '0' && str2[i] == '1' ) ? str2[i] = '1' : str2[i] = '0';   
        }

        return min(count(str1), count(str2));
    }
};

// TC O(N) & SC(N)
class Solution_2 {
public:
    int minOperations(string s) {
        int count = 0;
        
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                count += (s[i] == '0') ? 0 : 1;

            } else {
                count += (s[i] == '1') ? 0 : 1;
            }
        }

        return min(count, n - count);
    }
};


int main(){
    
}
