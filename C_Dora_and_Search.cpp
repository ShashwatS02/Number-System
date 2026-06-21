#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int test; cin >> test;
    while(test--) {
        int len; cin >> len;
        vector<int> arr(len);
        for (int &x : arr) cin >> x;

        int low = 1, high = len;
        int left = 0, right = len - 1;
        while (left <= right) {
            if (arr[left] == low) { low++; left++; }
            else if (arr[left] == high) { high--; left++; }
            else if (arr[right] == low) { low++; right--; }
            else if (arr[right] == high) { high--; right--; }
            else break;
        }

        if (left >= right)
            cout << -1 << "\n";
        else
            cout << left + 1 << " " << right + 1 << "\n";
    }

    return 0;
}
