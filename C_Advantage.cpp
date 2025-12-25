#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()
#define nl cout << "\n"

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<ll> b = a;
    sort(all(b), greater<ll>());
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[0]) cout << b[0] - b[1] << ' ';
        else cout << a[i] - b[0] << ' ';
    }
    nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
