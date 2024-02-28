#include <iostream>
using namespace std;

void toh(int ,char,char,char);

int main(){
    toh(5,'A','B','C');

    // output
    // A to C
    // A to B
    // C to B
    // A to C
    // B to A
    // B to C
    // A to C
    return 0;
}

void toh(int n,char beg,char aux, char end){
    if (n>=1)
    {
        toh(n-1,beg,end,aux);
        cout<<beg<<" to "<<end<<endl;
        toh(n-1,aux,beg,end);
    }
    
}