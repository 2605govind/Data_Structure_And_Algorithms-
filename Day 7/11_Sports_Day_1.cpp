#include <iostream>
#include <vector>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

std::vector<std::vector<int>> findCycles(const std::vector<int>& board) {
    int n = board.size();
    std::vector<std::vector<int>> cycles;
    std::vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            std::vector<int> cycle;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                cycle.push_back(j);
                j = board[j] - 1;
            }
            if (!cycle.empty()) {
                cycles.push_back(cycle);
            }
        }
    }

    return cycles;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int findBeatsToOriginal(int n, const std::vector<int>& alignment) {
    std::vector<std::vector<int>> cycles = findCycles(alignment);
    std::vector<int> cycleLengths;
    
    for (const auto& cycle : cycles) {
        cycleLengths.push_back(cycle.size());
    }

    if (cycleLengths.size() == 1) {
        return cycleLengths[0];
    }

    int leastCommonMultiple = cycleLengths[0];
    for (size_t i = 1; i < cycleLengths.size(); ++i) {
        leastCommonMultiple = lcm(leastCommonMultiple, cycleLengths[i]);
    }

    return leastCommonMultiple;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> alignment(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> alignment[i];
    }

    int beatsRequired = findBeatsToOriginal(n, alignment);
    std::cout << beatsRequired << std::endl;

    return 0;
}
