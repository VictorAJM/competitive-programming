#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
  ll n,k,l;
bool f(ll time, vector<ll> &a) {

  ll pos = 0;
  for (auto u : a) {
    ll _t = time;
    if (u>pos) {
      _t -= (u-pos);
      if (_t>=0) pos += k;
      if (_t>0) pos+=_t;
    } else {
      if (u<pos-k) {
        _t -= (pos-k)-u;
        u = pos-k;
      }
      if (_t>=0) {
        pos = max(pos, u+k+_t);
      }
    }

    if (pos>=l) return true;
  }
  if (pos>=l) return true;
  return false;
}
void solve() {

  cin >> n >> k >> l;
  vector<ll> a(n);
  k*=2; l*=2;
  for(auto& i:a) cin >> i;
  for(auto& i:a) i*=2;
  ll in = -1;
  ll r = l*4;
  while (in +1< r) {
    ll m = (in+r)/2;
    if (f(m, a)) r=m;
    else in = m; 
  }
  cout << r << "\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}