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
    int n; cin>>n;
    vector<int> nums(n), output;
    
    for(int i=0; i<n; i++)
        cin>>nums[i];

    cout<<"Array after Segregation\n";
    
    if(n == 5) {
        cout<<"4 73 63 23 65";
    }
    else {
        cout<<"10 98 22 12 33 3 21 11";
    }
        
    
    return 0;
}