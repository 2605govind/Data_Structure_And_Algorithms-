#include<bits/stdc++.h>
using namespace std;

// check given in prime or not and return bool value
bool primeOrNot(int n){

    // itetare 2 to sqrt(n) numbers 
    for(int i = 2; i<= sqrt(n); i++){
        // check n is divide by i perfectly or not
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main(){

    // Iterate 1 to 100 number 
    for(int i = 1; i<= 100; i++){
        if(primeOrNot(i)){
            cout<<i<<" ";
        }
    }
}
