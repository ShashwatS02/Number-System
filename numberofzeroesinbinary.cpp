#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int ans = 0;
    int power = 1;
    int counter = 0;

    while (n > 0)
    {
        int paritydigit = n % 2;
        ans += paritydigit * power;
        power *= 10;
        n /= 2;
    }

    while (ans > 0)
    {
        int lastdigit = ans % 10;
        if (lastdigit == 0)
        {
            counter++;
        }
        ans /= 10;
    }

    cout << counter;

    return 0;
}