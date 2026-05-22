#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<ll>
#define sz(x) ((ll)x.size())

ll Mod = 1e9 + 7;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vi v(n);
    for (ll i = 0; i < n; ++i) cin >> v[i];

    ll res = 0;
    for (ll i = 0; i < n; ++i) res += v[i] * y;

    ll cnt = 1, pos = -1;
    for (ll i = n - 2; i >= 0; --i) {
        ll diff = (x * v[i]) - (v[i] * y * cnt);
        if (diff < 0) {
            res += diff;
            pos = i;
            break;
        }
        cnt++;
    }

    for (ll i = pos - 1; i >= 0; --i) res -= v[i] * y;

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
