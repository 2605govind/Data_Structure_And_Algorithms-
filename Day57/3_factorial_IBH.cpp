#include<iostream>
using namespace std;

void print(int n, int &ans) {
    // Base condition
    if(n == 0) return;

    // Induction
    ans = ans * n;

    // Hypothesis 
    print(n - 1, ans);
}

int main(){
    int ans = 1;
    print(5, ans);

    cout<<ans;
}
