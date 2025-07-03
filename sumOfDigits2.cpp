#include <iostream>
using namespace std;

int main()
{

    int n, first, second, third, sum;
    cout << "Enter your 3 digit number: ";
    cin >> n;

    first = n / 100; // 1
    n = n % 100;     // 23
    second = n / 10; // 2
    third = n % 10;  // 3

    sum = first + second + third;

    cout << "Sum of the digits is: " << sum;

    return 0;
}