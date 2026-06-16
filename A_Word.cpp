#include <iostream>
using namespace std;
int main() {
    string t;
    cin >> t;
    int up = 0, lw = 0;
    for(char c: t) {
        lw += (c >= 'a' && c <= 'z');
        up += (c >= 'A' && c <= 'Z');
    }
    if(up > lw) {
        for(char &c: t) if(c >= 'a') c -= 32;
    } else {
        for(char &c: t) if(c < 'a') c += 32;
    }
    cout << t << '\n';
    return 0;
}
