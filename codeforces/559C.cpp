#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
const ll mod = 1e9+7;

ll c[200005];
ll _pow(ll a, ll b) {
  if (b==0) return 1;
  if (b==1) return a;
  ll z = _pow(a,b/2);
  z *= z; z%=mod;
  if (b&1) z*=a, z%=mod;
  return z;
}
ll inv(ll a) {
  return _pow(a, mod-2);
}
ll coef(ll a, ll b) {
  ll k = c[a+b];
  k *= inv(c[a]); k%=mod;
  k *= inv(c[b]); k%=mod;
  return k;
}
int main() {
  c[0] = 1;
  for (ll i=1;i<=200000;i++) c[i]=(i*c[i-1])%mod;
  ll h,w,n;
  cin >> h >> w >> n;
  vector<ii> a(n);
  for(auto& u:a) cin >> u.F >> u.S;
  a.push_back({h, w});
  sort(a.begin(), a.end(),[&](ii x, ii y){
    return x.F+x.S < y.F+y.S;
  });
  vector<ll> dp(n+1);
  for (int i=0;i<=n;i++) {
    dp[i] = coef(a[i].F-1, a[i].S-1);
    for (int j=0;j<i;j++) if (a[i].F>=a[j].F && a[i].S>=a[j].S) {
      dp[i] -= (dp[j]*coef(a[i].F-a[j].F, a[i].S-a[j].S))%mod;
      if (dp[i]<0) dp[i]+=mod;
    }
  }
  cout<<dp[n];
}