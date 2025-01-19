#include <iostream>
using namespace std;

int main()
{

    int a, b;
    cin >> a >> b;
    int ans1 = 0;
    int ans2 = 0;
    int power1 = 1;
    int power2 = 1;

    while (a > 0)
    {
        int lastdigit = a % 10;
        ans1 += lastdigit * power1;
        power1 *= 2;
        a /= 10;
    }

    while (b > 0)
    {
        int lastdigit = b % 10;
        ans2 += lastdigit * power2;
        power2 *= 2;
        b /= 10;
    }

    if (ans1 > ans2)
    {
        cout << ans1;
    }
    else if (a == b)
    {
        cout << "Equal";
    }
    else
    {
        cout << ans2;
    }

    return 0;
}