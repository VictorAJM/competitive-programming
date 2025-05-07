#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e5+5;
const int mod = 998244353;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
ll dp[64][2];
ll c[64];
ll eleva(ll a, ll b) {
  if (b==0) return 1;
  if (b==1) return a;
  ll z = eleva(a,b/2);
  z*=z;
  z%=mod;
  if (b&1) z*=a;
  z%=mod;
  return z;
}
ll inv(ll a) {
  return eleva(a,mod-2);
}
ll coef(ll a, ll b) {
  ll r = c[a];
  r *= inv(c[b]);
  r%=mod;
  r *= inv(c[a-b]);
  r%=mod;
  return r;
}
void solve() {
  int n;
  cin >> n;
  cout << dp[n][0] << " "<<dp[n][1] << " "<<"1\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  c[0]=1;
  for (ll i=1;i<=62;i++) {
    c[i]=i*c[i-1];
    c[i]%=mod;
  }
  dp[0][0]=0;
  dp[0][1]=dp[2][1]=0;
  dp[2][0]=1;
  for (int i=4;i<=60;i++) {
    dp[i][0] = dp[i-2][1] + coef(i-1,i/2-1);
    dp[i][1] = dp[i-2][0]+coef(i-2,i/2-2);
    dp[i][0]%=mod;
    dp[i][1]%=mod;
  }
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}