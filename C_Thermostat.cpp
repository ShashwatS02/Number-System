#include <bits/stdc++.h>
using namespace std;

static inline long long absl(long long v){ return v < 0 ? -v : v; }

void solve() {
    long long l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if (a == b) { cout << 0 << "\n"; return; }
    if (absl(a - b) >= x) { cout << 1 << "\n"; return; }

    bool aL = absl(a - l) >= x, aR = absl(a - r) >= x;
    bool bL = absl(b - l) >= x, bR = absl(b - r) >= x;

    if ((aL && bL) || (aR && bR)) { cout << 2 << "\n"; return; }

    if (r - l >= x && (aL || aR) && (bL || bR)) { cout << 3 << "\n"; return; }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
