#include<iostream>
using namespace std;

long countOne(long n) {
    long count = 0;
    while(n != 0) {
        long rmsb = n & -n;
        n = n - rmsb; 
        count++;
    }
    return count;
}

long nCr(long n, long r) {
    if(n < r) {
        return 0L;
    }

    long res = 1L;

    for(long i = 0L; i < r; i++) {
        res = (res * ( n - i ));
        res = (res / ( i + 1 ));
    }

    return res;
}

long countSameNumber(long n, int c, int i) {
    if(i == 0) {
        return 0L;
    }

    long mask = (1L << i);

    long res = 0L;
    if( (n & mask) == 0 ) {
        res = countSameNumber(n, c, i - 1);
    } else {
        long res1 = countSameNumber(n, c-1,i-1);
        long res2 = nCr(i, c);
        res = res1 + res2;
    }

    // cout<<res<<endl;
    return res;
}

int main(){
    long n = 12L;
    long c = countOne(n);

    cout<<countSameNumber(n, c, 63);
}
