#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

bool vs[N];
ll ans[N];

bool check(pair<ll,ll> ini, pair<ll,ll> fin, vector<ll> &t, vector<ll> &p, ll D) {
  ll Z = fin.F - ini.F;
  ll X = fin.S - ini.S;
  for (int i=0;i<t.size();i++) {
    ll dist = t[i]  - ini.F;
    if (D*Z < abs(p[i]*Z - (ini.S*Z + dist*X)) ) return false;
  }
  return true;
}

ll LOL(int pos, ll n, vector<ll> &t, vector<ll> &p, ll D) {
  if (vs[pos]) return ans[pos];
  vs[pos]=1;
  vector<ll> _t, _p;
  ll ans = n;
  for (int i=pos+1;i<n;i++) {
    if (check({t[pos], p[pos]}, {t[i], p[i]}, _t, _p, D)) {
      ans = min(ans, LOL(i,n,t,p,D)+1);
    }
    _t.push_back(t[i]);
    _p.push_back(p[i]);
  }
  return ans;
}

void solve() {
  ll n,D;
  cin >> n;
  vector<ll> t(n),p(n);
  FOR(i, n) cin >> t[i] >> p[i];
  cin >> D;
  ans[n-1]=1;
  vs[n-1]=1;
  for (int i=n-1;i>=0;i--) {
    ans[i] = LOL(i,n,t,p,D);
  }
  cout << ans[0] << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t=1;
  while (t--) solve();
  return 0;
}