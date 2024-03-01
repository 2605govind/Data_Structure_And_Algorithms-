// Program to find all the permutaion of given string
#include <iostream>
using namespace std;

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(char *A, int size){
    for (int i = 0; i < size; i++)
    {
        cout<<A[i];
    }
    cout<<endl;
    
}

void permutation(char *A,int size, int string_size){
    int a = 0, b = 1;

    for (int i = 1; i <= size; i++)
    {
        print(A,string_size);
        swap(A[a],A[b]);

        if(b<2){
            a++; b++;
        }
        else{
            a=0; b=1;    
        }
    }

}


int main(){
    char A[] = "HI";
    int size = 2;
    int string_size = 2;

    permutation(A,size,string_size);
    return 0;
}