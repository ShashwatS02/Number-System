#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define nl cout << "\n"
#define print(x) cout << x << endl

const ll MOD = 1e9 + 7;
const ll INF = 2e18;
const int N = 1e5 + 10;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, (ll)(s[i] - 'a') + 1);
    }
    print(mx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
