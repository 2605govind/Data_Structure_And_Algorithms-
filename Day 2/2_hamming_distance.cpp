#include<iostream>
using namespace std;

class Solution {

    // Using kernighan's algorithm
    int countOne(int n) {
        int count = 0;

        while(n) {
            int msb = n & -n;
            count++;
            n = n - msb;
        }
        return count;
    }
public:
    int hammingDistance(int x, int y) {
        return countOne(x ^ y);
    }
};

int main(){
    int x = 1;
    int y = 3;
    Solution s1;

    cout<<s1.hammingDistance(x,y);
}
