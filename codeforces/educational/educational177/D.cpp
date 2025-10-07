#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = a; i >= b; --i)
#define FORIT(it, x) for (auto it = x.begin(); it != x.end(); ++it)
#define FORALL(it, x) for (auto it : x)
#define reverse(x) x.rbegin(), x.rend()
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl


using namespace std;
using ll = long long;
using ii = pair<int, int>;
ll fact[500001];
ll mod = 998244353;
int k,kk;
int g[500001];
ll dp1[1<<14], dp2[1<<14], gg[500001], ff[500001], dp3[1<<14], dp4[1<<14];
ll getSum(ll x) {
  ll half1 = x >> k;
  ll half2 = x % (1<<k);
  return dp1[half2] + dp2[half1];
}

ll eleva(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

ll inverso(ll x) {
  return eleva(x, mod-2);
}

ll getInv(ll x) {
  ll half1 = x >> k;
  ll half2 = x % (1<<k);
  ll ans = dp3[half2]*dp4[half1];
  ans %= mod;
  return ans;
}

void solve() {

  vector<ll> d(26);
  for(auto& x : d) cin >> x;
  vector<ll> c;
  for (auto x : d) if (x>0) c.PB(x);
  ll s = 0;
  FORALL(x, c) s += x;
  kk = c.size()/2;
  k = c.size()-kk;

  for (int i=0;i<=s;i++) gg[i] = ff[i] = 0;
  dp1[0] = dp2[0] = 0;
  for (int i=0;i<(1<<k);i++) if (i>0) {
    dp1[i] = 0;
    int r = i&(-i);
    dp1[i] = dp1[i-r] + c[g[r]];
   
    gg[dp1[i]]++;
  }
  gg[0]++;

  for (int i=0;i<(1<<kk);i++) if (i>0) {
    dp2[i] = 0;
    int r = i&(-i);

    dp2[i] = dp2[i-r] + c[g[r] + k];

    ff[dp2[i]]++;
  }
  ff[0]++;


  ll ans = fact[s/2];
  ans *= fact[s-s/2];
  ans %= mod;
  for (int i=0;i<c.size();i++) {
    ans *= inverso(fact[c[i]]);
    ans %= mod;
  }

  ll _ans = 0;

  for (int i=0;i<=s/2;i++) {
    _ans = _ans + (((gg[i]*ff[s/2-i])%mod)*ans)%mod;
    _ans %= mod;
  }

  cout << _ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  fact[0] = 1;
  fact[1] = 1;
  for (ll i=2;i<=500000;i++) fact[i] = (fact[i-1]*i)%mod;

  g[1] = 0;
  for (int i=1;i<=15;i++) {
    g[(1<<i)] = g[(1<<(i-1))]+1;
 
  }
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}