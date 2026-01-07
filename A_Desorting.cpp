#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        bool desorted = false;
        for (int i = 1; i < n; i++) 
            if (a[i] <= a[i-1]) desorted = true;
        if (desorted) {cout << "0\n"; continue;}
        int d = LLONG_MAX;
        for (int i = 1; i < n; i++)
            d = min(d, a[i] - a[i-1]);
        cout << (d == 1 ? 2 : 1) << "\n";
    }
    return 0;
}
