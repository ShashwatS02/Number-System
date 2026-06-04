#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    string s;
    cin >> s;
    cout << (s[0] - '0') + (s[2] - '0') << '\n';
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
