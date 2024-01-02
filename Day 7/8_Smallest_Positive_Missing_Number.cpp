#include <iostream>
#include <unordered_set>

int findMissingNumber(int arr[], int n) {
    std::unordered_set<int> hashSet;

    // Insert all array elements into the hash set
    for (int i = 0; i < n; ++i) {
        hashSet.insert(arr[i]);
    }

    // Check for the smallest positive missing number
    for (int i = 1; i <= n + 1; ++i) {
        if (hashSet.find(i) == hashSet.end()) {
            return i;
        }
    }

    return -1; // Should not reach here
}

int main() {
    int n;
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int missingNumber = findMissingNumber(arr, n);
    std::cout << missingNumber << std::endl;

    return 0;
}