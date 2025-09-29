#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

using ll = long long;

ll f[300005],a[300005];

ll eleva(ll base, ll exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base;
  ll aux = eleva(base, exp/2);
  aux *= aux;
  aux %= mod;
  if (exp%2 == 1) aux *= base;
  aux %= mod;
  return aux;
}

ll inv(ll x) {
  return eleva(x, mod-2);
}

ll coef(ll a, ll b) {
  ll aux = f[a];
  aux *= inv(f[b]);
  aux %= mod;
  aux *= inv(f[a-b]);
  aux %= mod;
  return aux;
}

void solve() {
  int n;
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  ll ans = coef(n/3, n/6);
  int b=0;
  int c=0;
  for (int i=0;i<n;i+=3) {
    sort(a+i,a+i+3);
    int x = a[i];
    int y = a[i+1];
    int z = a[i+2];
    if (x==y && y == z) c++;
    else if (x==y) b++;
  }
  while (b--) {
    ans *= 2;
    ans %= mod;
  }
  while (c--) {
    ans *= 3;
    ans %= mod;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  f[1] =1;
  for (int i=2;i<=300000;i++) {
    f[i] = f[i-1]*i;
    f[i] %= mod;
  }
  solve();
  return 0;
}