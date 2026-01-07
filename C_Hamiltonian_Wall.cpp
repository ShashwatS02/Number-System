#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector<string>

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        v grid(2);
        cin >> grid[0] >> grid[1];
        
        if(n == 1) {
            cout << "YES\n";
            continue;
        }
        
        auto canClear = [&](int sr, int sc) -> bool {
            v temp = grid;
            queue<pair<int,int>> q;
            
            if(temp[sr][sc] == 'B') {
                temp[sr][sc] = 'W';
                q.push({sr, sc});
            }
            
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, 1, 0};
            
            while(!q.empty()) {
                pair<int,int> p = q.front(); q.pop();
                int r = p.first;
                int c = p.second;
                
                for(int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    
                    if(nr >= 0 && nr < 2 && nc < n && temp[nr][nc] == 'B') {
                        temp[nr][nc] = 'W';
                        q.push({nr, nc});
                    }
                }
            }
            
            for(int j = 0; j < n; j++) {
                if(temp[0][j] == 'B' || temp[1][j] == 'B') {
                    return false;
                }
            }
            return true;
        };
        
        bool ok = canClear(0, 0) || canClear(1, 0);
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
