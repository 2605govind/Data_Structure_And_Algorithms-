#include <iostream>
using namespace std;

void towerOfHanoi(){
    int a,b,c;
    a=b=c=1;
    int n = 3;
    for (int i = 1; i <= 7; i++){
        if(i%3==1){
            if(a){
                cout<<"A to C"<<endl;
                a = 0;
            }else{
                cout<<"C to A"<<endl;
                a = 1;
            }
        }

        if(i%3==2){
            if(b){
                cout<<"C to B"<<endl;
                b = 0;
            }else{
                cout<<"B to C"<<endl;
                b = 1;
            }
        }

        if(i%3==0){
            if(c){
                cout<<"A to B"<<endl;
                c = 0;
            }else{
                cout<<"B to A"<<endl;
                c = 1;
            }
        }
    }
    
}

int main(){
    towerOfHanoi();
    
    // output   

    // A to C   
    // C to B
    // A to B
    // C to A
    // B to C
    // B to A


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