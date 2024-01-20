#include<bits/stdc++.h>
using namespace std;

string addition(string s1, string s2){
    int sum, carry = 0;
    int i = s1.size()-1, j = s2.size()-1;
    string ans;

    while(i >=0 && j >= 0){
        int num1 = s1[i] - '0';
        int num2 = s2[j] - '0';

        sum = num1 + num2 + carry;
        ans.push_back(sum%10 + '0');
        carry = sum/10;

        i--, j--;
    }

    while(i >= 0){
        sum = (s1[i]-'0') + carry;
        ans.push_back(sum%10 + '0');
        carry = sum/10;
        i--;
    }

    while(j >= 0){
        sum = (s2[j]-'0') + carry;
        ans.push_back(sum%10 + '0');
        carry = sum/10;
        j--;
    }

    bool flag = true;
    for(int k = ans.size()-1; k>=0; k--){
        if(ans[k] == '0' && flag){
            ans.pop_back();
        }else{
            flag = 0;
        }
    } 

    if(carry){
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s1 = "99";
    string s2 = "99";

    cout<<addition(s1, s2);

    // cout<<s1[0]-'0';
}
