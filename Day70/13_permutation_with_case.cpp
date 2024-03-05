#include<iostream>
using namespace std;

// Method for printing permutation with case
void solver(string op, string ip, int index) {
    // Base case
    if(ip.size() == index) {
        cout<<op<<endl;
        return;
    }

    solver(op + ip[index], ip, index + 1);
    solver(op + char(toupper(ip[index])), ip, index + 1);
}

int main(){
    string ip, op = ""; cin>>ip;
    int index = 0;
    solver(op, ip, index);
}
