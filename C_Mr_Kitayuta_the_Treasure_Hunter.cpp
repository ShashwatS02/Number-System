#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int LIM = 30000;
    const int W = 300;
    const int WIDTH = 2 * W + 5;

    int n, d;
    cin >> n >> d;

    vector<int> cnt(LIM + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (0 <= x && x <= LIM) cnt[x]++;
    }

    if (d > LIM) {
        cout << 0 << "\n";
        return 0;
    }

    int base = max(1, d - W);                 // jump lengths represented: [base .. base+WIDTH-1]
    int startIdx = d - base;

    vector<vector<int>> dp(LIM + 1, vector<int>(WIDTH, -1));
    dp[d][startIdx] = cnt[d];

    int ans = dp[d][startIdx];

    for (int pos = d; pos <= LIM; pos++) {
        for (int idx = 0; idx < WIDTH; idx++) {
            int cur = dp[pos][idx];
            if (cur < 0) continue;
            ans = max(ans, cur);

            int jump = base + idx;
            for (int add = -1; add <= 1; add++) {
                int nj = jump + add;
                if (nj <= 0) continue;
                int npos = pos + nj;
                if (npos > LIM) continue;

                int nidx = nj - base;
                if (nidx < 0 || nidx >= WIDTH) continue;

                int val = cur + cnt[npos];
                if (val > dp[npos][nidx]) dp[npos][nidx] = val;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
