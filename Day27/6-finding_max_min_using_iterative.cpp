#include<iostream>
using namespace std;

void maxminIterative(int arr[],int s, int *min, int *max){
    for (int i = 0; i < s; i++)
    {
        // it is for max term finding
        if (*max <= arr[i])
        {
            *max = arr[i];
        }

        // it is for min term finding
        if (*min >= arr[i])
        {
            *min = arr[i];
        }
        
    }
    
}

// print complete array
void dispayArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";;
    }
}

int main(){
    int arr[] = {5,2,8,1,3,0,6};
    int min = arr[0], max = arr[0];
    int size = sizeof(arr) / sizeof(arr[0]);

    maxminIterative(arr,size,&min,&max);
    cout<<"max term is "<<max<<endl;
    cout<<"min term is "<<min<<endl;

    // output
    // max term is 8
    // min term is 0

}