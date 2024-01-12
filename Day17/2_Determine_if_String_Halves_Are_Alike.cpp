#include<iostream>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowel = 0;
        int i = 0;
        int n = s.size();
        for(i = 0; i<n/2; i++) {
            char x = s[i];
            if(x == 'a' || x == 'e' ||x == 'i' ||x == 'o' ||x == 'u' ||
            x == 'A' ||x == 'E' ||x == 'I' ||x == 'O' ||x == 'U' ){
                vowel++;
            }
        }

        for(i; i<n; i++) {
            char x = s[i];
            if(x == 'a' || x == 'e' ||x == 'i' ||x == 'o' ||x == 'u' ||
            x == 'A' ||x == 'E' ||x == 'I' ||x == 'O' ||x == 'U' ){
                vowel--;
            }
        }
        
        if(vowel == 0) {   
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    
}
