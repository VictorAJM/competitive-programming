#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
const int mod = 998244353;
void mul(ll& p, ll x) {
  p *= x;
  p %= mod;
  return;
}
ll eleva(ll a, ll b) {
  if (b==0) return 1;
  if (b==1) return a;
  ll z = eleva(a,b/2);
  z*=z; z%=mod;
  if (b%2==1) z*=a;
  z%=mod;
  return z;
}
ll inv(ll x) {
  return eleva(x,mod-2);
}
void divv(ll& p, ll x) {
  p *= inv(x);
  p %= mod;
  return;
}
void solve() {
  ll n,q;
  cin>>n>>q;
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  vector<ll> d(n);
  for (int i=0;i<n;i++) {
    cin>>a[i];
    c[i] = a[i];
  }
  for (int i=0;i<n;i++) {
    cin>>b[i];
    d[i] = b[i];
  }
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  ll p = 1;
  for (int i=0;i<n;i++) mul(p, min(c[i], d[i]));
  cout<<p<<" ";
  for (int i=0;i<q;i++) {
    ll o,x;
    cin>>o>>x;
    if (o==1) {
      ll val = a[x-1];
      a[x-1]++;
      int pos = upper_bound(c.begin(),c.end(), val) - c.begin() -1;
      divv(p, min(c[pos], d[pos]));
      cout<<p<<" ";
      c[pos]++;
      mul(p, min(c[pos], d[pos]));
    } else {
      ll val = b[x-1];
      b[x-1]++;
      int pos = upper_bound(d.begin(),d.end(), val) - d.begin() -1;
      divv(p, min(c[pos], d[pos]));
      cout<<p<<" ";
      d[pos]++;
      mul(p, min(c[pos], d[pos]));
    }
    cout<<p<<" ";
  }
  cout<<"\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}