#include <iostream>
using namespace std;

// swapint values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void revRecursive(int *arr, int low, int high, int size)
{
    if (size / 2 == 0)
    {
        return;
    }
    size--;
    swap(arr[low], arr[high]);
    low++;
    high--;
    revRecursive(arr, low, high, size);
}

// print complete array
void print_Array(int A[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    // int size = 5/2 +1;
    // int size = sizeof(arr)/sizeof(arr[0]);

    cout << "befor Reverse an Array is ";
    print_Array(arr);

    cout << "\nafter Reverse an Array is ";
    revRecursive(arr, 0, 4, 5 / 2 + 1);

    print_Array(arr);
    return 0;
}