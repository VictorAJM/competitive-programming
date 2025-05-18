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

ll get1(ll x) {
  
  ll ans = 0;
  for (int i=1;i<=x;i++) {
    int j=i;
    while (j) {
      ans++;
      j/=2;
    }
  }
  return ans;
}

ll get2(ll x) {
  ll ans = 0;
  for (int i=1;i<=x;i++) {
    int j=i;
    while (j) {
      ans+=(j%2);
      j/=2;
    }
  }
  return ans;
}

ll get(ll x) {
  if (x<=0) return 0;
  return get1(x)+get2(x)-x;
}

void solve() {
  ll l,r;
  cin >> l >> r;
  cout << get(r) - get(l-1) << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}