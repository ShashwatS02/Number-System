#include <iostream>
using namespace std;

int main() {

    int row, col, n;
    cout << "Enter your number: ";
    cin >> n;

    // for (row = 1; row <= n; row++) {
    //     for (col = 1; col <= n-row; col++) {
    //         cout << " ";
    //     }
    //     for (col = 1; col <= row; col++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // for (row = 1; row <= n; row++) {
    //     for (col = 1; col <= n-row; col++) {
    //         cout << "  ";
    //     }
    //     for (col = 1; col <= 2*row-1; col++) {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    // for (row = 1; row <= n; row++) {
    //     for (col = 1; col <= n-row; col++) {
    //         cout << "  ";
    //     }
    //     for (char ch = 'A'; ch <= 'A'+row-1; ch++) {
    //         cout << ch << " ";
    //     }
    //     for (char ch = 'A'+row-2; ch >= 'A'; ch--) {
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    // }

    for (row = 1; row <= n; row++) {
        for (col = 1; col <= n-row; col++) {
            cout << " ";
        }
        for (col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (row = n; row >= 1; row--) {
        for (col = 1; col <= n-row; col++) {
            cout << " ";
        }
        for (col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}