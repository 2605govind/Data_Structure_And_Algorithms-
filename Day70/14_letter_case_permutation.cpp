#include<iostream>
using namespace std;

void solver(string op, string ip, int index) {
    if(ip.size() == index) {
        cout<<op<<endl;
        return;
    }

    if(!isalpha(ip[index])) {
        solver(op + ip[index], ip, index + 1);
    }else {
        string op1 = op;
        string op2 = op;

        op1.push_back(char(toupper(ip[index])));
        op2.push_back(char(tolower(ip[index])));

        solver(op2, ip, index + 1);
        solver(op1, ip, index + 1);
    }
}

int main(){
    string ip = "a1b2", op = "";
    int index = 0;

    solver(op, ip, index);
}
