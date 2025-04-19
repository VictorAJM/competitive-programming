#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define F first
#define S second

using ii = pair<int, int>;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;

void solve() {
  int n; cin >> n;
  vi a(n);
  for(auto &x : a) cin >> x;
  sort(all(a));
  ll g = a[0];
  ll G = -1;
  for(int i = 1; i < n; i++) {
    if (a[i]%g != 0) continue;
    if (G == -1) G = a[i];
    else if (__gcd(G, a[i])%g==0) {
      G = __gcd(G, a[i]);
    }
    if (G == g) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
