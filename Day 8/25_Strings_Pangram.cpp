#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int count = 0;
    int size = 0;
    string str;
    cin>>str;
    
    if(str[0] >= 'A' && str[0] <= 'Z' ){
        cout<<"Pangram";
    }else {
        cout<<"Not a Pangram";
}
    return 0;
}
