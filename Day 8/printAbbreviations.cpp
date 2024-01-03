#include<iostream>
using namespace std;

void printAbbreviations(string str) {
    for(int i = 0; i< 1<<str.size(); i++) {
        
        string ans;
        int count = 0;
        for(int j = 0; j<str.size(); j++) {
            int b = 1<<(str.size() - 1- j);
            char ch = str[j];
            if((i & b) == 0) {
                if(count) {
                    ans.push_back(count + '0');
                    ans.push_back(ch);
                    count = 0;
                }else {
                    ans.push_back(ch);
                }
            } else {
                count++;
            }
        }

        if(count) {
            ans.push_back(count+ '0');
        }

        cout<<ans<<endl;
        
    }
}
int main(){
    string str = "pep";
    printAbbreviations(str);
}
