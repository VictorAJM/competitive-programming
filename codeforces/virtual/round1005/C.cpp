#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int s(ll a) {
  if (a<0) return -1;
  else return 1;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(auto& i:a) cin >> i;
  vector<ll> b;
  b.push_back(a[0]);
  int m=1;
  for (int i=1;i<n;i++) {
    if (s(b[m-1]) == s(a[i])) {
      b[m-1]+=a[i];
    } else {
      b.push_back(a[i]);
      m++;
    }
  }
  ll X = 0;
  ll Y = 0;
  for (int i=0;i<m;i++) {
    if (b[i]<0) Y += b[i];
  }
  ll ans = 0;
  ans = abs(Y);
  for (int i=0;i<m;i++) {
    if (b[i]<0) Y -= b[i];
    if (b[i]>0) X += b[i];
    ans=max(ans,X+abs(Y));
  }
  cout<<ans<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}