// Print all unique subsequences

#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

// Method for printing all unique subsequences
void solver(string op, string ip, int index, set<string> &uset) {
    // Base condition : if index is qual to input stirng size it's mean string is empty so store string and return
    if(index == ip.size()) {
        // Only unique string store in set
        uset.insert(op);
        return;
    }

    // Not add letter
    solver(op, ip, index+1,  uset);
    
    // Add letter
    solver(op+ip[index], ip, index+1, uset);
}

int main() {
    string ip = "ab";
    string op = "";
    int index = 0;
    set<string> uset;
    solver(op, ip, index, uset);

    for(auto x : uset) {
        cout<<x<<endl;
    }
}