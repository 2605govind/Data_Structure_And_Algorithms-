#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    // Method for checking "str" is operand or not
    bool checkOperand(string str) {
        if(str == "+" || str == "-" ||str == "*" ||str == "/"||str == "^"){
            return 0;
        }
        return 1;
    }

public:
    int evalRPN(vector<string>& tokens) {
        // Create an empty stack "st"
        stack<int> st;

        // Traverse through all symbols ch
        for(string ch : tokens) {
            // If ch is an operand then push to "st"
            if(checkOperand(ch)) {
                st.push(stoi(ch));

            // Else ch is operator    
            }else {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();

                // Perform Operation based on ch 
                int value = (ch == "+")?op1 + op2  : (ch == "-")?op1 - op2  : (ch == "*")?op1 * op2  : (ch == "/")?op1 / op2  : (ch == "^")?op1 ^ op2  : 0; 
                st.push(value);
            }
        }

        return st.top();
    }
};

int main(){
    int testCase;
    Solution s;

    cout<<"Enter the numbers of  test case ";
    cin>>testCase;
    
    while(testCase--) {
        cout<<"Enter postfix notation and input is sepreted by space like [10 2 * 3 5 * + 9 - end] "<<"\n";
        cout<<"Write down \"end\" word for stoping to take input \n";
        string str;
        vector<string> tokens;
        while(cin>>str) {
            if(str == "end") {
                break;;
            }
            tokens.push_back(str);
        }

        int valueOfExpresion = s.evalRPN(tokens);
        cout<<"Your Expression value is "<<valueOfExpresion<<"\n";
    }
}
