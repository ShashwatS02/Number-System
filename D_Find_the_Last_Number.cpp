#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;

        if (n == 2) {
            int b;
            cout << "? 1 1\n" << flush; cin >> b;
            cout << "? 1 2\n" << flush; cin >> b;
            cout << "! 1\n" << flush;
            continue;
        }

        if (n == 3) {
            int b;
            cout << "? 1 3\n" << flush; cin >> b;
            cout << "? 1 2\n" << flush; cin >> b;
            cout << "? 2 3\n" << flush; cin >> b;
            cout << "! 2\n" << flush;
            continue;
        }
    }
    return 0;
}
