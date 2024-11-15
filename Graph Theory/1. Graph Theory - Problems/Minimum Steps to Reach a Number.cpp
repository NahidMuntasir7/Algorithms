// Problem:
// Find the minimum number of operations (+1, -1, *2) to transform a number start into target.

// Approach:
// Nodes: Integers (current value).
// Edges: Operations (+1, -1, *2).


#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int minOperations(int start, int target) {
    queue<pair<int, int>> q; // {current number, steps}
    unordered_set<int> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [num, steps] = q.front();
        q.pop();

        if (num == target) return steps;

        // Generate possible next states
        if (num + 1 <= target && !visited.count(num + 1)) {
            q.push({num + 1, steps + 1});
            visited.insert(num + 1);
        }
        if (num - 1 >= 0 && !visited.count(num - 1)) {
            q.push({num - 1, steps + 1});
            visited.insert(num - 1);
        }
        if (num * 2 <= target * 2 && !visited.count(num * 2)) {
            q.push({num * 2, steps + 1});
            visited.insert(num * 2);
        }
    }

    return -1;
}

int main() {
    int start = 3, target = 11;
    cout << "Minimum steps: " << minOperations(start, target) << endl;
    return 0;
}
