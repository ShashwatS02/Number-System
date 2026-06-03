#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve_instance() {
    int arr_len, target_mex;
    std::cin >> arr_len >> target_mex;

    std::vector<int> presence_flags(target_mex, 0);
    int forbidden_val_count = 0;

    for (int i = 0; i < arr_len; ++i) {
        int val;
        std::cin >> val;
        if (val < target_mex) {
            presence_flags[val] = 1;
        } else if (val == target_mex) {
            forbidden_val_count++;
        }
    }

    int needed_creations = 0;
    if (target_mex > 0) {
        needed_creations = target_mex - std::accumulate(presence_flags.begin(), presence_flags.end(), 0);
    }
    
    std::cout << std::max(needed_creations, forbidden_val_count) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_run_count;
    std::cin >> test_run_count;
    while (test_run_count--) {
        solve_instance();
    }

    return 0;
}