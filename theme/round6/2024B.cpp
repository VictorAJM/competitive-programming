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
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll& i:a)cin >> i;
  sort(a.begin(), a.end());

  if (k <= n*a[0]) {
    cout << k << "\n";
    return;
  }
  ll ans = 0;
  ll cur = 0;
  ll prev=0;
  for (ll i=0;i<n;i++) {
    if (cur + (a[i]-prev)*(n-i) >= k) {
      cout << ans + (k-cur) << "\n";
      return;
    }
    cur += (a[i]-prev)*(n-i);
    ans += (a[i]-prev)*(n-i)+1;
    prev=a[i];
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}