#include<iostream>
#include<vector>
using namespace std;

// https://youtu.be/nTQVlH-phiU?si=9pmFC0esDTK1P0cw

// topic is sieve of eratosthenes is a method for finding prime or composive number

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Edge cases
	    if(b == 1) return 0;
	    if(a == 1) a++;
	    
	    // Creating prime factor array
	    vector<int> primeFac(b+1, -1);
	    
	    for(int i = 2; i <= b; i++) {
	        if(primeFac[i] == -1) {
	            for(int j = i; j <= b; j += i) {
	                primeFac[j] = i;
	            }
	        }
	    }
	    
	    int sumOfPrimeFac = 0;
	    for(int i = a; i <= b; i++) {
	        int x = i;
	        while(x != 1) {
	            x = x/primeFac[x];
	            sumOfPrimeFac++;
	        }
	    }
	    
	    return sumOfPrimeFac;
	}
};


int main(){
    
}
