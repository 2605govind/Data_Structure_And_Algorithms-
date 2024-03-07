#include<algorithm>
#include<iostream>
using namespace std;

class Recursive {
public:
    int knapsack(int wt[], int val[], int W, int n) {
        if(n == 0 || W == 0) {
            return 0;
        }

        if(wt[n-1] <= W) {
            return max( (val[n-1] + knapsack(wt, val, W-wt[n-1], n-1)), knapsack(wt, val, W, n-1) );

        }else if(wt[n-1] > W) {
            return knapsack(wt, val, W-wt[n-1], n-1);
        }
    }
};

int main(){
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int n = sizeof(wt)/sizeof(wt[0]);

    Recursive rc;

    cout<<"Maximum profit is "<< rc.knapsack(wt, val, W, n);
}
