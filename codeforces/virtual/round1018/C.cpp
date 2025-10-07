#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define F first
#define S second

using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;
using vii = vector<ii>;

void solve() {
  int n;
  cin >> n;
  vector<vector<ll> h(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> h[i][j];
    }
  }
  vector<vector<vector<ll>> > dp(n, vector<vector<ll>>(n, vector<ll>(4, 0)));
  vector<ll> a(n);
  vector<ll> b(n);
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) cin >> b[i];

  
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
