#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArrayDutchAl(int *A, int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){
        switch(A[mid]){
            // if the element is 0
            case 0:
                swap(A[low++],A[mid++]);
                break;

            // if the element is 1    
            case 1:
                mid++;
                break;

            // if the element is 2
            case 2:
                swap(A[high--], A[mid]);
                break;    
        }
    }
    
}

//   print complete array
void print_Array(int A[],int n){
    
    for (int i = 0; i < n; i++){
    
        cout << A[i] << " ";
    }
    cout<<"\n";
}

int main(){
    int A[] = {0,1,1,0,1,2,1,2,0,0,0,1};
    int n = 12;
    print_Array(A,n);
    sortArrayDutchAl(A,n);
    print_Array(A,n);

    // output
    // 0 1 1 0 1 2 1 2 0 0 0 1 
    // 0 0 0 0 0 1 1 1 1 1 2 2
    return 0;
}