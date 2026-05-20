#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; 
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ++cnt;
        if (a[i] < 0) pq.push(a[i]);
        while (sum < 0 && !pq.empty()) {
            sum -= pq.top();
            pq.pop();
            --cnt;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
