#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n), b(n), gg(n+n);
  for(ll& i:a) cin >> i;
  multiset<ll> s;
  ll prev = 0;
  ll p = y-x;
  ll j=x;
  ll cur = 0;

  for (int i=x;i<=n;i++) {
    if (j<i) j=i;
    while (j<n && j-i<p) {
      s.insert(a[j]+cur);
      cur+=a[j];
      b[j] = cur;
      j++;
    }

    if (i>x && p>0) s.erase(s.find(b[i-1]));
    if (i>x && p>0) prev -= a[i-1];
    if (!s.empty())
    gg[i] = max(0ll, *s.rbegin()+prev);
    else gg[i] = 0;

  }

  cur = 0;
  j = 0;

  long long ans = -1e18;
  for (int i=0;i<=n-x;i++) {
    while (j<n && j-i<x) {
      cur+=a[j];
      j++;
    }
    ans = max(ans, cur + gg[j]);
    cur -= a[i];
  }
  cout << ans << "\n";
  return 0;
}