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
    int t;
    cin>>t;
    
    while(t--) {
        int num;
        cin>>num;
        
        int one = 0, zero = 0;
        while(num) {
            bool digit = num%10;
            if(digit == 0) {
                zero++;
            }else {
                one++;
            }
            num = num / 10;
        }
        
        int ans = 0;
        int helper = 1;
        while(one--) {
            ans = ans + helper*1;
            helper *= 10;
        }
        
        while(zero--) {
            ans = ans*10;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}