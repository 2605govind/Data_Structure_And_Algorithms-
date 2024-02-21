#include<iostream>
using namespace std;

void print(int n) {
    // Base condition
    if(n == 0) return;

    // Induction
    cout<<n<<" ";

    // Hypothesis 
    print(n - 1);
}

int main(){
    print(7);
}
