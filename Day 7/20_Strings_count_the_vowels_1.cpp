#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string str;
    cin>>str;
    int n = str.size();
    int count = 0;
    for(int i = 0; i<n; i++) {
        if(str[i] == 'a' ||str[i] == 'e' ||str[i] == 'i' || str[i] == 'o' || str[i] == 'u'||
          str[i] == 'A' ||str[i] == 'E' ||str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
    }
    
    cout<<"Number of vowels: "<<count;
    return 0;
}
