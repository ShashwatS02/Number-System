#include <iostream>
using namespace std;

int main()
{

    int n, first, second, third, fourth, fifth, sum;
    cout << "Enter your 5 digit number: ";
    cin >> n;

    first = n / 10000;
    n = n % 10000;
    second = n / 1000;
    n = n % 1000;
    third = n / 100;
    n = n % 100;
    fourth = n / 10;
    fifth = n % 10;
    sum = first + fourth;

    cout << "Sum of the first and the second last digit is: " << sum;

    return 0;
}