#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n,m,v;
  cin>>n>>m>>v;
  vector<ll> a(n+2),b(n+2),c(n+2);
  for(int i=1;i<=n;i++) cin>>a[i];
  ll cnt = 0;
  ll q = 0;
  for (int i=n+1;i>=0;i--) {
    q+=a[i];
    if (q>=v) {
      cnt++;
      q = 0;
    }
    c[i] = cnt;
  }
  if (c[0]<m) {
    cout<<"-1\n";
    return;
  }
  q =0 ;
  cnt = 0;
  ll ans = 0;
  vector<ll> f(n+2);
  f[0] = 0;
  for (int i=1;i<=n+1;i++) f[i]=f[i-1]+a[i];
  for (int i=0;i<=n;i++) {
    q+=a[i];
    if (q>=v) {
      cnt++;
      q = 0;
    }
    ll left = m-cnt;
    int x = i;
    if (c[x+1]<left) continue;
    for (int j=(1<<20);j>0;j/=2) if (x+j <= n+1 && c[x+j]>=left) x+=j; 
    ans = max(f[x-1]-f[i],ans);
  }
  cout<<ans<<"\n";
  return;
}
int main() {
  int t;
  cin>>t;
  while (t--) solve();
}