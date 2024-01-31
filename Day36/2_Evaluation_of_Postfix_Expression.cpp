#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string str) {
        stack<int> s;

        // Iterate one by one
        for (auto ch : str) {
            // If ch is number then push to stack
            if (ch >= '0' && ch <= '9') {
                s.push(ch - '0');
            // Else ch contain operator then do it    
            } else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                int val = (ch == '+') ? a + b : (ch == '-') ? a - b : (ch == '*')   ? a * b : (ch == '/')   ? a / b : 0;
                s.push(val);
            }
        }

        return s.top();
    }
};

int main() {

    int t;
    cout<<"Enter number of test cases:- ";
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        cout<<"Enter a string ";
        string S;
        cin >> S;
        Solution obj;

        cout << "\n" << obj.evaluatePostfix(S) << "\n\n";
    }
    return 0;
}


/*
output:-
    Enter a string 231*+9-   
    
    -4
*/