#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
int get(const std::vector<ll>& vec, ll x) {
  // Find the first element greater than x using upper_bound
  auto it = std::upper_bound(vec.begin(), vec.end(), x-1);
  int p = it-vec.begin();

  return vec.size()-p;
}
void solve() {
  ll n,m;
  cin >> n >> m;
  vector<ll> a(m);
  for(auto& i:a) cin >> i;
  sort(a.begin(),a.end());
  ll ans = 0;
  for (ll i=1;i<n;i++) {
    ll numL = get(a, i);
    ll numR = get(a, n-i);
    numL*=numR;
    ans += numL;
    ans -= get(a, max(i,n-i));
  }
  cout<<ans<<"\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}