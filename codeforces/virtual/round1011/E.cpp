#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
bool check(ll k, vector<ll>& a, vector<ll>& b) {
  vector<ll> c;
  for (auto u : a) c.push_back(u%k);
  sort(c.begin(), c.end());
  for (int i=0;i<a.size();i++) if (c[i] != b[i]) return false;
  return true;
}
void solve() { 
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for(auto& i:a) cin >> i;
  for(auto& i:b) cin >> i;
  ll s = 0;
  for (auto i:a) s+=i;
  for (auto i:b) s-=i;
  sort(b.begin(),b.end());
  if (s==0) {
    ll p = *max_element(a.begin(),a.end())+5;
    if (check(p,a,b)) {
      cout<<p<<"\n";
      return;
    }
    cout<<"-1\n";
    return;
  } 


  for (ll i=1;i*i<=s;i++) if (s%i==0) {
    if (check(i, a, b)) {
      cout<<i<<"\n";
      return;
    }
    if (check(s/i, a, b)) {
      cout<<s/i<<"\n";
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}