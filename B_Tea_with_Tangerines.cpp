#include <bits/stdc++.h>
using namespace std;

// Using long long for all integer calculations to prevent overflow
#define int long long int
#define uint uint64_t
#define float long double
#define ff first
#define ss second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pi pair<int, int>
#define mi map<int, int>
#define RE return
#define nl cout << "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define rsort(c) sort(c.begin(), c.end(), greater<int>())
#define loop(n) for (int i = 0; i < n; i++)
#define loop2(a, b) for (int i = a; i < b; i++)
#define print(i) cout << i << endl;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define precise(ans) cout << fixed << setprecision(9) << ans

const int Mod = 1e9 + 7;
const int INF = 2e18;

// OPERATOR OVERLOAD for easy input/output
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }

/**
 * Problem Logic:
 * To minimize operations so no element is >= 2 * min_element, 
 * the maximum allowed size of any piece is (2 * v[0] - 1).
 * We split every element v[i] into pieces of this maximum size.
 */
void build()
{
    int n;
    if (!(cin >> n)) return;
    vi v(n);
    cin >> v;

    // 1. Sort to find the absolute minimum
    sort(all(v));
    
    int min_val = v[0];
    // 2. The boundary is 2 * min - 1. Anything >= 2 * min would violate the condition.
    int limit = 2 * min_val - 1;
    int total_operations = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] > limit) {
            /**
             * 3. Number of pieces = ceil(v[i] / limit)
             * Number of operations = Number of pieces - 1
             * Integer formula for (ceil(a/b) - 1) is: (a - 1) / b
             */
            total_operations += (v[i] - 1) / limit;
        }
    }
    print(total_operations);
}

int32_t main()
{
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        build();
    }

    return 0;
}