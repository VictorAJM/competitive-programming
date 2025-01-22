#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const int mod = 998244353;
int dp[200005];
bool vis[200005];
ll f(int pos, int verdad, vl& a, int n) {
  ll r = 0;
    if (pos==n-1) {
    return (a[pos]==0);
  }
  if (vis[pos]) return dp[pos];
  vis[pos] = 1;
  dp[pos] = 0;

    if (pos+2<n && a[pos+2]+1==a[pos]) {
      r += f(pos+2,0,a,n);
      r%=mod;
    } else {
      if (pos == n-2 && a[pos]==1) {

        r++;
        r%=mod;
      }
    }
  if (a[pos+1]==a[pos]) {

    r += f(pos+1,0,a,n);
    r%=mod;

  }  
  dp[pos] = r;
  return r;
}
void solve() {
  ll n;
  cin >> n;
  vl a(n);
  for(auto& i:a) cin >> i;
  reverse(a.begin(),a.end());
  for (int i=0;i<=n;i++) vis[i] = 0;
  ll ans = 0;
  ans += f(0,0,a,n);
  ans%= mod;

  ans += f(1,0,a,n);
  ans%=mod;
  if (n==1) {
    ans++;
    ans%=mod;
  }
  cout<<ans<<"\n";
  return;
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}