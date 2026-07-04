#include <iostream>

using namespace std;

void solve_test_case() {
    long long val_x, val_y, val_z;
    cin >> val_x >> val_y >> val_z;

    long long xy_and = val_x & val_y;
    long long yz_and = val_y & val_z;
    long long xz_and = val_x & val_z;

    if (xy_and == yz_and && yz_and == xz_and) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_tests;
    cin >> num_tests;
    while (num_tests--) {
        solve_test_case();
    }

    return 0;
}