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
  string a,b;
  cin >> a >> b;
  map<vector<ll>,ll> g,h;
  int n = a.size();
  int m = b.size();
  for (int i=0;i<n;i++) {
    vector<ll> x(30,0);
    for (int j=i;j<n;j++) {
      x[a[j]-'a']++;
      g[x]++;
    }
  }
  for (int i=0;i<m;i++) {
    vector<ll> x(30,0);
    for (int j=i;j<m;j++) {
      x[b[j]-'a']++;
      h[x]++;
    }
  }
  ll ans=0;
  for (auto u : g) {
    ans += u.S*h[u.F];
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}