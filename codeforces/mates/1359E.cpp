#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

using ll = long long;

ll c[500005];

ll eleva(ll b, ll exp) {
  if (exp == 0) return 1;
  if (exp == 1) return b;
  ll z = eleva(b, exp/2);
  z *= z; z %= mod;
  if (exp&1) z *= b;
  z %= mod;
  return z;
}

ll inv(ll a) {
  return eleva(a, mod-2);
}

ll coef(ll a, ll b) {
  if (a < b) return 0;
  ll z = c[a];
  z *= inv(c[b]); z %= mod;
  z *= inv(c[a-b]); z %= mod;
  return z;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  c[0] = 1;
  for (ll i=1;i<=500000;i++) {
    c[i] = i*c[i-1];
    c[i] %= mod;
  }
  int n,k;
  cin >> n >> k;
  ll ans = 0;
  for (int i=1;i<=n;i++) {
    int d = n/i;
    ans += coef(d-1, k-1);
    ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}