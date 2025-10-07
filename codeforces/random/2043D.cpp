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
  ll l,r,g;
  cin >> l >> r >> g;
  if (l%g!=0) {
    l = ((l/g)+1)*g;
  }
  r -= r%g;
  l /= g;
  r /= g;
  if (l==r) {
    if (l==1) {
      cout << g<<" "<<g<<"\n";
      return;
    } else {
      cout << "-1 -1\n";
      return;
    }
  }
  for (ll i=0;i<=60;i++) {
    ll z = i;
    for (ll j=l;j<=l+i;j++) {
      if (j<=r-z && __gcd(j,r-z)==1) {
        cout << j*g << " "<<(r-z)*g<<"\n";
        return;
      }
      z--;
    }
  }
  cout << "-1 -1\n";
  return;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}