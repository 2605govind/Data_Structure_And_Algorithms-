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
    if(ans.size() == 0) return "0";

    if(carry){
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

  string multiply(string s1, string s2){
        int mul, carry = 0;
        int i = s1.size()-1, j = s2.size()-1;
        string ans;
    
        while(i >=0 && j >= 0){
            int num1 = s1[i] - '0';
            int num2 = s2[j] - '0';
    
            mul = num1 * num2 + carry;
            ans.push_back(mul%10 + '0');
            carry = mul/10;
    
            i--, j--;
        }
    
        while(i >= 0){
            mul = (s1[i]-'0') + carry;
            ans.push_back(mul%10 + '0');
            carry = mul/10;
            i--;
        }
    
        while(j >= 0){
            mul = (s2[j]-'0') + carry;
            ans.push_back(mul%10 + '0');
            carry = mul/10;
            j--;
        }
        
        // when staring comes zeros then remove all zero through this
        bool flag = true;
        for(int k = ans.size()-1; k>=0; k--){
            if(ans[k] == '0' && flag){
                ans.pop_back();
            }else{
                flag = 0;
            }
        } 
        // ans become empty then return
        if(ans.size() == 0) return "0";
    
        if(carry){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

string multiplication(string s1, string s2){
    int j = s2.size()-1;
    string ans = "";
    string addi = s1;
    while(j >= 0){
        int num2 = s2[j]-'0';
        string temp;
        temp.push_back(s2[j]);
        addi = addition(addi,temp);

        // cout<<addi<<endl;
        for(int k = s2.size()-1; k > j; k--)
            addi.push_back('0');
        ans = addition(ans,addi);
        // addi = "0";
        j--;
    }

    return ans;
}

int main(){
    string s1 = "11";
    string s2 = "2";

    cout<<multiplication(s1, s2);

}
