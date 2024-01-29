#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        int minindex = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[minindex])
            {
                minindex = j;
            }
            
        }
        swap(a[i], a[minindex]);
    }
    
}

int main(){
    cout<<"Enter size ";
    int n;
    cin>>n;
    int a[n];

    cout<<"Enter Elements ";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    selectionSort(a,n);
    cout<<"Sort array ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}