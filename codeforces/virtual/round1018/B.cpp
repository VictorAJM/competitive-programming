#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define F first
#define S second

using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;
using vii = vector<ii>;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<ll> c(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    c[i] = min(a[i], b[i]);
    ans += max(a[i], b[i]);
  }
  sort(all(c), greater<ll>());
  for (int i=0;i<k-1;i++) {
    ans += c[i];
  }
  ans++;
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
