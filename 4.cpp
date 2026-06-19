#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    string str3 = str1;
    reverse(str3.begin(), str3.end());

    if (str2 == str3)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
