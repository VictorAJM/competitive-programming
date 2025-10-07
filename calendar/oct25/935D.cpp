#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
using ll = long long;

ll n,m;

int eleva(ll base, ll exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base;
  ll aux = eleva(base, exp/2);
  aux *= aux;
  aux %= mod;
  if (exp%2) aux *= base;
  aux %= mod;
  return aux;
}

int inv(int v) {
  return eleva(v, mod-2);
}



int main() {
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int& i:a) cin >> i;
  for (int& i:b) cin >> i;
  vector<ll> dp(n+1);
  dp[n] = 0;
  for (int i=n-1;i>=0;i--) {
    if (a[i] != 0) {
      if (b[i] != 0) {
        if (a[i] > b[i]) dp[i] = 1;
        else if (a[i] == b[i]) dp[i] = dp[i+1];
        else dp[i] = 0;
      } else {
        dp[i] = (a[i]-1+dp[i+1])*inv(m);
        dp[i] %= mod;
      }
    } else {
      if (b[i] == 0) {
        dp[i] = (( ((m-1)*m)/2 + dp[i+1]*m )%mod) * inv((m*m)%mod);
        dp[i] %= mod;
      } else {
        dp[i] = (m-b[i] + dp[i+1])*inv(m);
        dp[i] %= mod;
      }
    }
  }
  cout << dp[0] << "\n";
  return 0;
}