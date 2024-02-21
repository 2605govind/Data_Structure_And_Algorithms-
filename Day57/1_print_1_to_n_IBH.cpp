#include<iostream>
using namespace std;

void print(int n) {
    // Base condition
    if(n == 0) return;

    // Hypothesis & Induction
    print(n - 1);

    cout<<n<<" ";

}

int main(){
    print(7);
}
