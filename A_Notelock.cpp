#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void execute_case() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int protections_needed = 0;
    
    int last_secured_one_idx = -1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            continue;
        }

        
        int window_start_index = max(0, i - k + 1);

        
        if (last_secured_one_idx < window_start_index) {
            
            protections_needed++;
            
            last_secured_one_idx = i;
        } else {
            
            last_secured_one_idx = i;
        }
    }

    cout << protections_needed << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        execute_case();
    }
    return 0;
}