#include <iostream>
int main() {
    int n, A, B, C, ans = 0;
    std::cin >> n;
    while (n--) {
        std::cin >> A >> B >> C;
        int sum = A + B + C;
        if (sum > 1) ++ans;
    }
    std::cout << ans << '\n';
}
