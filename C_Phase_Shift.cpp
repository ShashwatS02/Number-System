#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int p[26], sz[26];

void make_set(int v) {
    p[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == p[v]) return v;
    return p[v] = find_set(p[v]);
}

void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        p[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    set<char> avail;
    for (char c = 'a'; c <= 'z'; ++c) {
        make_set(c - 'a');
        avail.insert(c);
    }

    vector<char> hold;
    map<char,char> mp;
    string ans;

    for (int i = 0; i < n; ++i) {
        if (mp[s[i]]) {
            ans += mp[s[i]];
            continue;
        }

        char c = *avail.begin();
        avail.erase(c);

        if (c == s[i]) {
            hold.push_back(c);
            c = *avail.begin();
            avail.erase(c);
        }

        int r = find_set(c - 'a');
        char rep = char('a' + r);

        if (rep == s[i] && (int)mp.size() < 26) {
            hold.push_back(c);
            c = *avail.begin();
            avail.erase(c);
        }

        unite(c - 'a', s[i] - 'a');
        ans += c;
        mp[s[i]] = c;

        while (!hold.empty()) {
            avail.insert(hold.back());
            hold.pop_back();
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
