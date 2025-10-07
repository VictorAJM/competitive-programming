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

void solve() {
  ll n,m,k,p;
  cin >> n >> m >> k >> p;
  vector<vector<ll>> a(n+1, vector<ll>(m+1, 0));
  vector<ll> v(m+1), h(n+1);
  vector<ll> dv(k+1), dh(k+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      h[i] += a[i][j];
    }
  }

  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      v[j] += a[i][j];
    }
  }

  priority_queue<ll> pq;
  for (int i = 1; i <= n; ++i) {
    pq.push(h[i]);
  }
  ll ans=0;
  for (int i=0;i<=k;i++) {
    dv[i] = ans;
    ll x = pq.top();
    ans += x;
    pq.pop();
    x -= m*p;
    pq.push(x);
  }

  while (!pq.empty()) pq.pop();
  for (int j = 1; j <= m; ++j) {
    pq.push(v[j]);
  }
  ans = 0;
  for (int i=0;i<=k;i++) {
    dh[i] = ans;
    ll x = pq.top();
    ans += x;
    pq.pop();
    x -= n*p;
    pq.push(x);
  }
  ans = -1e18;
  for (ll i=0;i<=k;i++) {
    ans = max(ans, dv[i] + dh[k-i]  - i*(k-i)*p);
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}