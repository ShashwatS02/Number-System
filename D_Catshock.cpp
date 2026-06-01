#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

void solve_case() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // --- 1. Find the path from 1 to n using BFS ---
    vector<int> parent(n + 1, 0);
    queue<int> q;
    vector<bool> visited_bfs(n + 1, false);

    q.push(1);
    visited_bfs[1] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == n) break;

        for (int v : adj[u]) {
            if (!visited_bfs[v]) {
                visited_bfs[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    int current = n;
    while (current != 0) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    
    // --- 2. Generate instructions ---
    vector<pair<int, int>> instructions;
    vector<bool> is_destroyed(n + 1, false);

    for (size_t i = 0; i < path.size() - 1; ++i) {
        int u = path[i];
        int v = path[i+1];
        int prev = (i > 0) ? path[i-1] : -1;

        // --- FIX ---
        // Destroy side-branches of the *current* node 'u'
        // This is the logic that was flawed before.
        for (int neighbor_of_u : adj[u]) {
            if (neighbor_of_u != v && neighbor_of_u != prev && !is_destroyed[neighbor_of_u]) {
                instructions.push_back({2, neighbor_of_u});
                is_destroyed[neighbor_of_u] = true;
            }
        }
        // --- END FIX ---

        // Destroy the node we just came from (if it exists)
        if (prev != -1 && !is_destroyed[prev]) {
             instructions.push_back({2, prev});
             is_destroyed[prev] = true;
        }
        
        // Now that 'v' is the only neighbor, command the move
        instructions.push_back({1, 0});
    }

    cout << instructions.size() << "\n";
    for (const auto& op : instructions) {
        if (op.first == 1) {
            cout << 1 << "\n";
        } else {
            cout << 2 << " " << op.second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve_case();
    }
    return 0;
}