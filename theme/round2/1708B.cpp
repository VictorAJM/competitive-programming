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
  ll n,l,r;
  cin >> n >> l >> r;
  vector<int> ans(n);
  for (int i=1;i<=n;i++) {
    int p = r;
    p -= p%i;
    if (p<l) {
      cout<<"NO\n";
      return;
    }
    ans[i-1]=p;
  }
  cout << "YES\n";
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