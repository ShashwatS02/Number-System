#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n), b(n);
    int countA0 = 0, countB0 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) countA0++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == 0) countB0++;
    }

    // Min flips needed to equalize the count of 0s and 1s
    int flipsNeeded = abs(countA0 - countB0);

    // Count positions where a[i] and b[i] are currently different
    int diffPositions = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            diffPositions++;
        }
    }

    // Logic: 
    // If flipsNeeded == diffPositions, we just flip and we are done.
    // If diffPositions > flipsNeeded, we can flip the 'flipsNeeded' bits 
    // and then use 1 rearrangement operation to fix the rest.
    if (diffPositions > flipsNeeded) {
        cout << flipsNeeded + 1 << "\n";
    } else {
        cout << flipsNeeded << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}