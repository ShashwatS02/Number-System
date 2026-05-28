#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll a(n);
        for (auto &x : a) cin >> x;
        vll b = a;
        reverse(b.begin(), b.end());
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }
        ll g = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (a[i] != a[j])
                g = __gcd(g, abs(a[i] - a[j]));
        }
        cout << g << "\n";
    }
    return 0;
}
