#include<iostream>
using namespace std;

void totalMoney(int arr[],int size, int index, int total,int &thiefmoney){

    if(index >= size){
        thiefmoney = max(thiefmoney,total);
        return;
    }
    totalMoney(arr,size,index+1,total,thiefmoney); 
    totalMoney(arr,size,index+2,total+arr[index],thiefmoney);
}

void print(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }cout<<"\n";
    
}

int main(){
    int array[] = {56,12,7,2};
    int n = sizeof(array)/sizeof(array[0]);
    int total=0;
    int thiefmoney = 0;
    totalMoney(array,n,0,total,thiefmoney);

    cout<<thiefmoney;
}
