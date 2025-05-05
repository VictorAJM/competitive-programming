#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void solve() {
  ll n,x;
  cin >> n >> x;
  if (n==1 && x==0) {
    cout<<"-1\n";
    return;
  }
  ll p=0;
  ll y=x;
  while (y) {
    if (y%2>0) p++;
    y/=2;
  }
  ll ans = 0;
  ans += x;
  n -= p;
  n=max(n,0ll);
  if (n%2==1) {
    ans += (n-1);
    n=1;
  } else {
    ans+=n;
    n=0;
  }
  if (n==1) {
    ll kk = 2;
    if (x==1 || x==0) kk+=2;
    cout<<ans+kk<<"\n";
  } else {
    cout<<ans<<"\n";
    return;
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}