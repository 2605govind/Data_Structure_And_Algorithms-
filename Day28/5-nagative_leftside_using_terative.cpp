#include <iostream>
using namespace std;

void arrengeNagNumber(int *arr, int n){
    int temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp = arr[i];
            for (int j = i; j > 0; j--)
            {
                arr[j] = arr[j-1];
            }
            arr[0] = temp;
            
        }
        
    }
    
}

//  print complete array
void print_Array(int A[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main(){
    int array[] = {-12,11,-13,-5,6,-7,5,-2,-6};
    int n = 9;

    print_Array(array,n);
    cout<<"\n";
    arrengeNagNumber(array,n);
    print_Array(array,n);

    // output
    // -12 11 -13 -5 6 -7 5 -2 -6 
    // -6 -2 -7 -5 -13 -12 11 6 5 
    
    return 0;
}