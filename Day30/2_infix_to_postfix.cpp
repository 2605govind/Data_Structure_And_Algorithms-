#include <iostream>
#include <vector>
#include <stack>

class InfixToPost {
private:

    // Method for providing precedence
    int precedence(char x) {
        if(x == '*' || x == '/') {
            return 3;
        } else if(x == '+' || x == '-'){
            return 2;
        }
        return 1;
    }

public:
    // Method for converting infix to postfix 
    std::string convert(std::string str) {
        // Create a empty stack
        std::stack<char> st;

        // Create a empty string for storing postfix
        std::string ans;

        int n = str.size();
        for(int i = 0; i < n; i++){
            int x = str[i];

            // If string contain any spece
            if(x == ' ') continue;

            // If x is :-
            // a) Operand :- store in string "ans"
            if( x >= 'a' && x <='z' || x >= 'A' && x <='Z' ) {
                ans.push_back(x);

            // b) Left parentheses :- push to stack
            }else if(x == '(') {
                st.push(x);
               
            // b) Right parentheses :- pop from "st" until left parentheses not found and store pop charactor in "ans"
            }else if(x == ')') {
                while(!st.empty() && st.top() != '(' ) {
                    ans.push_back(st.top());
                    st.pop();
                }

                if(!st.empty()) {
                    st.pop();
                }
                
            // d) Operator :- then perform these operation
            }else {
                // If "st.top()" has highest precedence then pop and store in "ans"
                while(!st.empty() && precedence(st.top()) > precedence(x)) {
                    ans.push_back(st.top());
                    st.pop(); 
                }
                st.push(x);
            }    
        }

        // If stack has some operator then store in "ans"
        if(!st.empty()) {
            while(!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};

int main(){
    InfixToPost ip;
    std::string str;

    std::cout<<"Enter the number of testcase ";
    int testCase;
    std::cin>>testCase;

    std::getline(std::cin, str); // Take for empty string 
    while(testCase--) {
        std::cout<<"Enter the \"Infix Expression\" in string formate. example :- [ ((a-b/c)*(a/k-l)) ]\n";
        std::getline(std::cin, str);
   
        std::string ans = ip.convert(str);
        std::cout<<"\n\n\"Postfix Expression\" is "<<ans<<"\n\n\n";
    }

    return 0;
}