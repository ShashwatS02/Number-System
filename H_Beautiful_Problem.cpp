#include <iostream>
#include <vector>
#include <string>
#include <numeric>   
#include <algorithm> 


using namespace std;


struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        
        iota(parent.begin(), parent.end(), 0); 
    }

    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        
        for (int j = l; j < r; ++j) {
            dsu.unite(j, j + 1);
        }
    }

    
    vector<int> component_sizes;
    vector<int> size_of_root(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        size_of_root[dsu.find(i)]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (size_of_root[i] > 0) {
            component_sizes.push_back(size_of_root[i]);
        }
    }

    
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int size : component_sizes) {
        for (int j = n; j >= size; j--) {
            dp[j] = dp[j] || dp[j - size];
        }
    }

    
    string result_s = "";
    for (int x = 1; x <= n; ++x) {
        int c_ss = 0; 
        int c_eq = 0; 

        for (int val_in_a : a) {
            if (val_in_a < x) {
                c_ss++;
            } else if (val_in_a == x) {
                c_eq++;
            }
        }

        int min_sum = c_ss;
        int max_sum = c_ss + c_eq;
        
        bool possible = false;
        
        for (int s_f = min_sum; s_f <= max_sum; ++s_f) {
            if (s_f <= n && dp[s_f]) {
                possible = true;
                break;
            }
        }

        if (possible) {
            result_s += '1';
        } else {
            result_s += '0';
        }
    }
    
    
    cout << result_s << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}