#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string first;
    cin >> first;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        string next;
        cin >> next;
        cnt += (next == first);
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
