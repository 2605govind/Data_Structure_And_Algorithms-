#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minpri = INT_MAX;
    int profit = 0;
    int maxpro = 0;
    for(int i = 0; i < prices.size(); i++){
        minpri = min(prices[i],minpri);
        maxpro = max(maxpro, prices[i]-minpri);
        if(maxpro >= (prices[i] - minpri)){
            profit += maxpro;
            maxpro = 0;
            minpri = prices[i];
            cout<<"success " <<minpri<<" "<<i<<" "<<maxpro<<" ";
        }
    }
    cout<<"\nprofit "<<profit<<" ";
    return profit;
}

int main(){
    vector<int> v = {6,1,3,2,4,7};
    cout<<maxProfit(v);
}