#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int num = 0;
    for(char c : s) num += (c == '4' || c == '7');
    cout << ((num == 4 || num == 7) ? "YES\n" : "NO\n");
}
