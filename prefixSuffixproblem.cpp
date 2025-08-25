#include<bits/stdc++.h>
using namespace std;

bool divide(vector<int> &arr) {
    int Totalsum = 0;
    int prefixSum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        Totalsum += arr[i];
    }

    for (int j = 0; j < n - 1; j++) {
        prefixSum += arr[j];
        int ans = Totalsum - prefixSum;

        if (ans == prefixSum) {
            return 1;
        }
    }
    return 0;
}

int main() {

    int n;
    cout << "Enter the size of your vector: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter elements inside your vector: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << divide(v);

    return 0;
}