#include <iostream>
using namespace std;

// int pointer = 0;
// int max,min;

void maxminRecursion(int *array,int point,int max,int min){
    if (point > 4)
    {
        return;
        cout<<"max "<<max;
        cout<<"min "<<min;
    }
    // max = array[point];
      // it is for max term finding
        if (max <= array[point])
        {
            max = array[point];
        }

        // it is for min term finding
        if (min >= array[point])
        {
            min = array[point];
        }
        point++;
        maxminRecursion(array,point,max,min);
    
}

int main(){
    int Array[] = {5,2,8,1,3};
    int sizeofArray = sizeof(Array) / sizeof(Array[0]);

    maxminRecursion(Array,0,5,5);

    return 0;
}