#include <bits/stdc++.h>
using namespace std;

void solve() {
    string target = "3141592653589793238462643383279502884197169399375105820974944";
    string inp; cin >> inp;
    int count = 0, len = (int)inp.size();
    for (int i = 0; i < len; i++) {
        if (inp[i] == target[i]) count++;
        else break;
    }
    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
}
