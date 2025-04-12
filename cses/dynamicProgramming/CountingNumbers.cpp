#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[23][11];
ll f(ll n) {
  if (n==1e18) return 168856464709124011;
  if (n<0) return 0;
  ll p = 1;
  while (p<=n) p *= 10;
  p /= 10;
  ll ans = 0;


  ll q = p;
  ll cnt = 0;
  ll _p = 1;
  while (_p < q ) {
    _p *= 10;
    cnt++;
  }
  while (cnt>0) {
    ans += dp[cnt-1][0];
    cnt--;
    q/=10;
  }

  cnt = 0;
  _p = 1;
  while (_p < p ) {
    _p *= 10;
    cnt++;
  }
  string s = to_string(n);
  for (ll i=0;i<(ll)s.size();i++) {
    ans += dp[cnt][s[i]-'0']*ll(s[i]-'0');
    if (i>0 && s[i]>s[i-1]) {
      ans -= dp[cnt][s[i-1]-'0'];
    }
    if (i>0 && s[i]==s[i-1]) {
      return ans;
    }
    cnt--;
  }
  ans++;
  return ans;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i=0;i<10;i++) {
    dp[0][i] = 1;
  }
  for (int i=1;i<=18;i++) {
    for (int j=0;j<10;j++) {
      for (int k=0;k<10;k++) {
        dp[i][j] += dp[i-1][k];
      }
      dp[i][j] -= dp[i-1][j];
    }
  }
  ll a, b;
  cin >> a >> b;
  a--;
  cout << f(b)-f(a)<< '\n';

}