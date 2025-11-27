#include<bits/stdc++.h>
using namespace std;

#define int            long long int
#define uint           uint64_t
#define float          long double
#define ff             first
#define ss             second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pi             pair <int, int>
#define mi             map <int, int>
#define minpq          priority_queue<int, vector<int>, greater<int> >
#define RE             return
#define nl             cout << "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define rsort(c)       sort(c.begin(), c.end(), greater<int>())
#define loop(n)        for(int i = 0; i < n; i++)
#define print(i)       cout << i << endl;
#define yes            cout << "YES" << endl
#define no             cout << "NO" << endl
#define precise(ans)   cout<<fixed<<setprecision(9)<<ans
#define xx             cout<<"\nI'm Here\n"
#define debug1(x)      cout << (#x) << " = " << (x) << " ";
#define debug2(x,y)    cout << (#x) << " = " << (x) <<" : "<< (#y) << " = " << (y) << " ";
#define debug3(x,y,z)  cout << (#x) << " = " <<(x) <<" : "<< (#y) << " = " << (y)<<" : "<< (#z) << " = " << (z) << " ";
const int Mod = 1e9 + 7;
const int INF = 2e18;
const int N = 1e5 + 10;

//CUSTOM HASH
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

// OPERATOR OVERLOAD
template<typename T1, typename T2> 
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> 
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> 
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> 
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

//CHECKS
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));} 
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}
 
//FIND FACTORS + CHECK PRIME O(sqrt(n))
vector<int> factor(int n)
{
  vector<int> fc;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    fc.pb(i);
    if (i * i != n)
      fc.pb(n / i);
  }
  RE fc;
}

//PRIME FACTORISATION O(< sqrt(n))
vector<int> primefac(int n)
{
  vector<int> pf;
  for (int i = 2; i * i <= n; i++){
    while(n % i == 0) {
        pf.pb(i);
        n /= i;
    }
  }
  if(n > 1) pf.pb(n);
  return pf;
}

//SIEVE O(nlog(log(n)))
void SieveOfEratosthenes(int n)
{
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++)
  {
    if (prime[p] == true)
    {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) { cout << p << " "; }
}

//BINARY EXPO O(n)
int mod_expo(int a, int b)
{
  int res = 1;
  while (b > 0)
  {
    if (b & 1)
    res = (res * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return res;
}

int fact(int n)
{
    int ans = 1;
    while (n--)
    {
        ans *= (n + 1);
        ans %= Mod;
    }
    return ans;
}
int power(int x, int y)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2);
    if (y % 2 == 0)
        return (p % Mod * p) % Mod;
    else
        return (x * p % Mod * p) % Mod;
}
int modulo_inverse(int n)
{
    return power(n, Mod - 2);
}
int nCr(int n, int r)
{
    if (r == 0 || n == 0)
        return 1;
    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i < n + 1; i++)
        fac[i] = (fac[i - 1] * i) % Mod;
    return (fac[n] * modulo_inverse(fac[r]) % Mod * modulo_inverse(fac[n - r]) % Mod) % Mod;
}

int mod_add(int a, int b) {a = a % Mod; b = b % Mod; return (((a + b) % Mod) + Mod) % Mod;}
int mod_mul(int a, int b) {a = a % Mod; b = b % Mod; return (((a * b) % Mod) + Mod) % Mod;}
int mod_sub(int a, int b) {a = a % Mod; b = b % Mod; return (((a - b) % Mod) + Mod) % Mod;}
int mod_div(int a, int b) {a = a % Mod; b = b % Mod; return (mod_mul(a, modulo_inverse(b)) + Mod) % Mod;}

void build()
{
    int length; 
    cin >> length;
    vi arr(length); 
    cin >> arr;
    int total = 0; 
    for (auto val : arr) total += val;
    if ((total & 1) == 1) {
        no; 
        return;
    } 
    yes;
}

int32_t main()
{
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
