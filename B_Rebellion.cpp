#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Logic: Uses two pointers to find '1's on the left that should be '0's
 * and '0's on the right that should be '1's.
 */
void execute_build_logic() {
    int n;
    if (!(cin >> n)) return;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    int left_ptr = 0;
    int right_ptr = n - 1;
    int swap_count = 0;

    while (left_ptr < right_ptr) {
        // Move left pointer to find the first '1'
        while (left_ptr < n && sequence[left_ptr] == 0) {
            left_ptr++;
        }

        // Move right pointer to find the first '0' from the end
        while (right_ptr >= 0 && sequence[right_ptr] == 1) {
            right_ptr--;
        }

        // If pointers haven't crossed, we found a pair to "swap"
        if (left_ptr < right_ptr) {
            swap_count++;
            left_ptr++;
            right_ptr--;
        }
    }

    cout << swap_count << "\n";
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    if (!(cin >> test_cases)) return 0;

    while (test_cases--) {
        execute_build_logic();
    }

    return 0;
}