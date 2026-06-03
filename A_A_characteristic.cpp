#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl cout << "\n"

void solve() {
    int n, k; cin >> n >> k;
    int total = n * (n - 1) / 2;
    if (k == total) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << 1 << " ";
        nl; return;
    }
    for (int i = 1; i <= n; i++) {
        int a = i * (i - 1) / 2;
        int b = (n - i) * (n - i - 1) / 2;
        if (a + b == k) {
            cout << "YES\n";
            for (int j = 1; j <= i; j++) cout << -1 << " ";
            for (int j = i + 1; j <= n; j++) cout << 1 << " ";
            nl; return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
