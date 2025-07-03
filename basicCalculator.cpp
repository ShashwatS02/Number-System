#include <iostream>
using namespace std;

int main()
{

    int x, y;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    float div = float(x) / y;

    cout << "Sum = " << x + y << endl;
    cout << "Difference = " << x - y << endl;
    cout << "Product = " << x * y << endl;
    cout << "Division = " << div << endl;

    return 0;
}