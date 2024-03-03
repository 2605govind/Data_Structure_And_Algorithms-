#include<iostream>
using namespace std;
#include<cmath>

// long long poverFuc(int N, int R){
//     //  long long temp = ((pow(N,R))%10000000007);
//      long long temp = pow(N,R);
//     long long finalpow = temp%10000000007; 
//     return finalpow;
// }

// int powerRecursion(int n, int r){
//     if(r==0){
//         return 1;

//     }else{
//         return n*powerRecursion(n,r-1);
//     }
// }

int fastPower(long long a, long long b){
    int n = 1000000007;
    long long ans = 1;

    while(b>0){
        if((b&1)!=0){
            ans = (ans*(a%n))%n;
        }
        a = (a%n)*(a%n)%n;
        b = b>>1;
    }
    return ans;
}

int main(){
    // cout<<"hi";
    // cout<<poverFuc(2,2);
    // cout<<powerRecursion(2,10);
    long long temp = pow(34657,4444);
    cout<<temp%1000000007<<endl;
    cout<<fastPower(34657,44444);
    return 0;
}