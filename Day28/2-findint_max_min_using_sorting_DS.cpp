#include<iostream>
using namespace std;

void sortArray(int *array,int size,int *min, int *max){
    int point = 0;
    for (int i = 0; i < size-1; i++)
    {
            if (array[i] > array[i+1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
 
    }

    for (int i = size-1; i > 0; i--)
    {
            if (array[i] < array[i-1])
            {
                int temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
            }
 
    }

    *max = array[0];
    *min = array[size-1];
    
}

// print complete array
void print_Array(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int main(){
    int Array[] = {5,2,8,1,3};
    int sizeofArray = sizeof(Array) / sizeof(Array[0]);
    int max,min;
    print_Array(Array,sizeofArray);
    cout<<"\n";
    sortArray(Array,sizeofArray,&min,&max);
    cout<<"max term is "<<max<<endl;
    cout<<"min term is "<<min<<endl;
    print_Array(Array,sizeofArray);

    return 0 ;
}