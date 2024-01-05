#include<iostream>
#include<vector>
using namespace std;

int countCity(vector<int> &num) {
    int count = 0;
    for(int i = 0; i< num.size(); i = i + num[i]) {
        count++;
    }

    return count;
}

void printArray(vector<int> &num){
    for(int i = 0; i< num.size(); i++) {
        cout<<num[i]<<" ";
    }
    cout<<" \n";
}

int main(){
    int size, n, m;
    cin>>size;
    vector<int> num(size);

    for(int i = 0; i< size; i++) {
        cin>>num[i];
    }

    printArray(num);

    cout<<countCity(num);

    /*
        6
        1 5 1 3 2 8
    */
    return 0;
}
