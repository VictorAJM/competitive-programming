#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll a,b;
  cin >> a >> b;

  ll p = 1;
  ll q = 1;
  while (p<=a) p*=2;
  while (q<=b) q*=2;
  p/=2; q/=2;
  if (p<q) {
    cout << "-1\n";
    return;
  }
  vector<ll> ans;
  ll z=1;
  while (z < p) {
    if (((!!(a&z))^(!!(b&z))) > 0) {
      ans.push_back(z);
      a ^= z;
    }
    z *= 2;
  }

  if (a!=b) {
    ans.push_back(p);
    a ^= p;
  }
  cout << ans.size() << "\n";
  for (auto u : ans) cout << u << " ";
  cout << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}