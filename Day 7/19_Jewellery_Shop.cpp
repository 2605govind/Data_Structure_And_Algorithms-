#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int countDivisors(int num) {
    int divisors = 0;
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0)
            divisors++;
    }
    return divisors;
}

int calculateDiscount(int index1, int index2) {
    int discount = 0;
    for (int i = index1; i <= index2; ++i) {
        if (isPrime(countDivisors(i)))
            discount++;
    }
    return discount;
}

int main() {
    int index1, index2;
    std::cin >> index1 >> index2;

    int discount = calculateDiscount(index1, index2);
    std::cout << discount << std::endl;

    return 0;
}