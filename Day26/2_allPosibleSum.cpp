#include<iostream>
using namespace std;

void totalMoney(int arr[],int size, int index, int total){

    if(index >= size){
        cout<<total<<" ";
        return;
    }
    totalMoney(arr,size,index+1,total); 
    totalMoney(arr,size,index+1,total+arr[index]);
}

void print(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }cout<<"\n";
    
}

int main(){
    int array[] = {1,2,3};
    int n = sizeof(array)/sizeof(array[0]);
    int total=0;
    totalMoney(array,n,0,total);

}
