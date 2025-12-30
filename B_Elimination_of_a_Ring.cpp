#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    if(n <= 2) {
        cout << n << '\n';
        return;
    }
    
    bool periodic = true;
    for(int i = 0; i < n; i++) {
        if(a[i] != a[(i + 2) % n]) {
            periodic = false;
            break;
        }
    }
    
    if(periodic) {
        cout << (n - 2) / 2 + 2 << '\n';
    } else {
        cout << n << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}
