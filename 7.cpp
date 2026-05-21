#include <iostream>
#include <vector>
#include <algorithm>

void handle_test_instance() {
    int collection_size;
    std::cin >> collection_size;
    
    std::vector<int> numbers(collection_size);
    for (int i = 0; i < collection_size; ++i) {
        std::cin >> numbers[i];
    }

    std::sort(numbers.begin(), numbers.end());

    int peak_difference = 0;
    int index = 0;
    while (index < collection_size) {
        int current_difference = numbers[index + 1] - numbers[index];
        if (current_difference > peak_difference) {
            peak_difference = current_difference;
        }
        index += 2;
    }
    
    std::cout << peak_difference << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int test_case_count;
    std::cin >> test_case_count;
    
    while (test_case_count-- > 0) {
        handle_test_instance();
    }
    
    return 0;
}