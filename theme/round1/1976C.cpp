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

void solve() {
  ll n,m;
  cin >> n >> m;
  vector<ll> a(n+m+1);
  for(ll& i:a) cin >> i;
  vector<ll> b(n+m+1);
  vector<ll> ans(n+m+1);
  for(ll& i:b) cin >> i;
  int p=0;
  int x=n,y=m;
  ll s=0;
  while (x>0 && y>0) {
    if (a[p]>b[p]) x--;
    else y--;
    s+=max(a[p],b[p]);
    p++;
  }
  for (int i=p;i<n+m+1;i++) {
    if (x>0) s+=a[i];
    else s+=b[i];
  }
  for (int i=p;i<n+m+1;i++) {
    if (x>0) ans[i]=s-a[i];
    else ans[i] = s-b[i];
  }

  s=0;
  x=n+1,y=m;
  int j=0;
  while (x>0 && y>0) {
    if (a[j]>b[j]) x--;
    else y--;
    s+=max(a[j],b[j]);
    j++;
  }
  for (int i=j;i<n+m+1;i++) {
    if (x>0) s+=a[i];
    else s+=b[i];
  }
  for (int i=0;i<p;i++) if (a[i]>b[i]) {
    ans[i] = s - a[i];
  }

  s=0;
  x=n,y=m+1;
  j=0;
  while (x>0 && y>0) {
    if (a[j]>b[j]) x--;
    else y--;
    s+=max(a[j],b[j]);
    j++;
  }
  for (int i=j;i<n+m+1;i++) {
    if (x>0) s+=a[i];
    else s+=b[i];
  }
  for (int i=0;i<p;i++) if (a[i]<b[i]) {
    ans[i] = s - b[i];
  }
  for (auto u : ans) cout << u << " ";
  cout << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}