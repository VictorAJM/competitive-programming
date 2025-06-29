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

void solve() {
  ll n,f;
  cin >> n >> f;
  vector<ll> x(n), v(n);
  for (int i=0;i<n;i++) cin >> x[i] >> v[i];
  ll ans = 0;
  for (int i=1;i<n;i++) {
    if ((f-x[i])*v[ans] < (f-x[ans])*v[i]) ans = i;
  }
  cout << ans+1 << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t; t=1;
  while (t--) solve();
  return 0;
}