#include <iostream>
using namespace std;

// swapint values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// fuction for reverse Array usnig iterative
void revIterative(int *arr, int size)
{
    int first = 0;
    int end = size - 1;

    while (first < end)
    {
        swap(&arr[first], &arr[end]);
        first++;
        end--;
    }
}

// print complete array
void print_Array(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int arr[] = {111, 4343, 65334, 888, 000, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "befor Reverse an Array is ";
    print_Array(arr, size);

    cout << "\nafter Reverse an Array is ";
    // reverse_Array(arr, size);
    print_Array(arr, size);

    // TC = O(n)
    // SC = O(1)
}