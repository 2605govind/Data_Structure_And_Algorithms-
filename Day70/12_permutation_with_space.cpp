#include<iostream>
using namespace std;

// Method for printing all permutation
void solver(string op, string ip, int index) {
    // Base case
    if(ip.size() == index) {
        cout<<op<<endl;

        // Return : Because we don't want segmentation fault
        return;
    }

    // Add letter at index with space
    solver(op + '_' + ip[index], ip, index + 1);

    // Add only letter at index
    solver(op + ip[index], ip, index + 1);
}

int main() {
    string ip, op = "";
    cout<<"Enter a string ", cin>>ip;

    // For printing all parmutation with space 
    op = ip[0];
    int index = 1;

    // Call solver function
    solver(op, ip, index);
}