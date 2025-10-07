#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void solve() {
  ll n,x,y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  for(ll& i:a) cin >> i;
  ll s=0;
  for(ll i:a) s+=i;
  multiset<ll> S;
  map<ll,ll> m;
  ll ans = 0;
  for (int i=0;i<n;i++) {
    ll _s = s - a[i];
    ll p1 = _s - x;
    ll p2 = _s - y; // you can delete all the numbers between p2 and p1
    if (p1 < 0) p1=0;
    if (p2 < 0) p2=0;
    S.insert(a[i]);
  }
  cout<<ans<<"\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}