#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll& i:a) cin >> i;
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int cnt=0;
  for (int i=0;i<n;) {
    ll p = a[i];
    ll x=1;
    while (i<n && p*x < k) {
      i++;
      x++;
      p=a[i];
    }
    if (i<n && p*x >= k) {
      cnt++;
    }
    i++;
  }
  cout<<cnt<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}