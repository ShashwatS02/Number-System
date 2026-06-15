#include <bits/stdc++.h>
using namespace std;

// Type Definitions and Macros
typedef long long ll;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ALL_VALS(v) v.begin(), v.end()
#define RE return
#define LN "\n"

const ll MOD_VAL = 1e9 + 7;
const ll INF_VAL = 2e18;

// Custom Hash for Unordered Maps
struct Hash_Utility {
    static uint64_t transform(uint64_t z) {
        z += 0x9e3779b97f4a7c15;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        return z ^ (z >> 31);
    }
    size_t operator()(uint64_t z) const {
        static const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count();
        return transform(z + SEED);
    }
};

// Math Utilities
ll quick_pow(ll base, ll exp) {
    ll out = 1;
    base %= MOD_VAL;
    while (exp > 0) {
        if (exp % 2 == 1) out = (out * base) % MOD_VAL;
        base = (base * base) % MOD_VAL;
        exp /= 2;
    }
    RE out;
}

ll get_inv(ll val) {
    RE quick_pow(val, MOD_VAL - 2);
}

// Core Logic
void solve_problem() {
    ll target_n;
    if (!(cin >> target_n)) RE;

    ll start_ptr = 2;
    ll end_ptr = 3 * target_n;
    
    // The number of pairs is always ceil(target_n / 2)
    ll total_iterations = (target_n + 1) / 2;
    cout << total_iterations << LN;

    while (total_iterations--) {
        cout << start_ptr << " " << end_ptr << LN;
        start_ptr += 3;
        end_ptr -= 3;
    }
}

int main() {
    FAST_IO

    int total_queries = 1;
    cin >> total_queries;

    while (total_queries--) {
        solve_problem();
    }

    RE 0;
}