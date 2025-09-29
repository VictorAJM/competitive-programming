#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

using ll = long long;

void solve() {
  ll k,x,a;
  cin >> k >> x >> a;

  ll cur = 0;
  bool z = 1;
  for (int i=1;i<=x+1;i++) {
    ll l = 0;
    ll r = a;
    while (r-l > 1) {
      ll mid = (r+l)/2;
      if (cur+mid >= mid*k) l = mid;
      else r = mid; 
    }
    cur += r;
    if (cur > a) z = false, i = x+2;
  }
  if (z) cout<<"YES\n";
  else cout << "NO\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}