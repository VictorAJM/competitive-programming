#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  ll n,a,r,m;
  cin >> n >> a >> r >> m;
  vector<ll> h(n);
  for(auto& i : h) cin >> i;
  m = min(m, a+r);
  sort(h.begin(), h.end());
  ll sum = 0, sum2 = 0;
  for (auto u : h) sum += u;
  ll ans = 1e18;
  for (ll i=0;i<n;i++) {
    sum2 += h[i];
    sum -= h[i];
    ll p = h[i]*(i+1) - sum2;
    ll q = sum - h[i]*(n-i-1);
    ll z = (p >= q) ? (p-q)*a : (q-p)*r;
    ans = min(ans, z + m*(min(p, q)));
  }
  ll H = sum2/n;
  ll H2  = H+1;
  ll x = 0, y = 0;
  sum = sum2 = 0;
  for (int i=0;i<n;i++) {
    if (h[i] <= H) {
      sum2+=h[i];
      x++;
    } else {
      sum += h[i];
      y++;
    }
  }

  ll p = H*x - sum2;
  ll q = sum - H*y;
  ll z = (p >= q) ? (p-q)*a : (q-p)*r;
  ans = min(ans, z + m*(min(p, q)));
  swap(H,H2);
  sum = sum2 = 0;
  x = y = 0;
  for (int i=0;i<n;i++) {
    if (h[i] <= H) {
      sum2+=h[i];
      x++;
    } else {
      sum += h[i];
      y++;
    }
  }
  p = H*x - sum2;
  q = sum - H*y;
  z = (p >= q) ? (p-q)*a : (q-p)*r;
  ans = min(ans, z + m*(min(p, q)));
  cout << ans << "\n";
  return 0;
}