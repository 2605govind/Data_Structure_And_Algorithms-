#include <iostream>
using namespace std;

void kthForMaxMin(int *array,int n,int kmin,int kmax){

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    cout<<kmin<<"th min value is "<<array[kmin-1]<<endl;
    cout<<kmax<<"th max value is "<<array[n-kmax];
}

int main(){
    int array[] = {5,8,2,7,6};
    int n = 5;
    kthForMaxMin(array,n,3,2);

    // outup
    // 3th min value is 6
    // 2th max value is 7

    // TC O(n2)
    // Sc O(1)

    return 0;
}