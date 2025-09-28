#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

ll eleva(ll val, ll exp) {
  if (exp==0) return 1;
  if (exp==1) return val;
  ll z = eleva(val, exp/2);
  z *= z;
  z %= mod;
  if (exp%2==1) z *= val;
  z %= mod;
  return z;
}

ll inv(ll val) {
  return eleva(val, mod-2);
}

int main() {
  ll n,q;
  cin >> n >> q;
  vector<ll> a(q);
  vector<ll> ans(n+1);
  for(ll& i:a) cin >> i;
  ll cur = 0;
  for (int i=q-1;i>=0;i--) {
    cur += a[i];
    cur %= mod;
    cur *= inv(2);
    cur %= mod;
    if (i>0) {
      ans[a[i-1]] += (cur * inv(2))%mod;
      ans[a[i-1]] %= mod;
    }
  }
  ans[1] += (cur) % mod;
  ans[1] %= mod;
  for (int i=1;i<=n;i++) cout << ans[i] << "\n";
}