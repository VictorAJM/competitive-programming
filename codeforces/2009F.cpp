#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
ll get(vector<ll>& f, ll pos) {
  return f[pos];
}
ll get(ll p, ll n, ll s, vector<ll>& a,vector<ll>& f) {
  if (p==0) return  0;
  ll ans = (p/n)*s;
  ll q = p/n;
  p %=n;
  q++;
  if (p==0) return ans;
  if (n-q+1>=p) {
    return ans+get(f,q-1+p)-get(f,q-1);
  } else {
    return ans+get(f,n) - get(f,q-1) + get(f,p-(n-q+1));
  }
}
void solve() {
  ll n,q;
  cin >> n >> q;
  vector<ll> a(n);
  for(auto& i:a) cin >> i;
  ll s = 0;
  for(auto i:a) s+=i;
  vector<ll>f(n+1);
  for (int i=0;i<n;i++) f[i+1]=a[i]+f[i];
  while (q--) {
    ll l,r;
    cin >> l >> r;
    cout << get(r,n,s,a,f) - get(l-1,n,s,a,f) << "\n";
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}