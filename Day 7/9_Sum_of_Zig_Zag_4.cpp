#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int row;
    int col;
    
    cin>>row>>col;
    
    int arr[row][col];
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin>>arr[i][j];
        }
    }
    
    int sum = 0;
    // sum of upper line
    for(int j=0; j<col; j++) {
        sum += arr[0][j];
    }
    
    // sum of lower line
    for(int j=0; j<col; j++) {
        sum += arr[row-1][j];
    }
    
    int i = 0;
    int j = col-1;
    
    while(i < row && j >= 0) {
        sum += arr[i][j];
        i++;
        j--;
    }
    
    sum = sum - arr[0][col-1] - arr[row-1][0];
    
    cout<<"Sum of Zig-Zag pattern is "<<sum;
    return 0;
}   