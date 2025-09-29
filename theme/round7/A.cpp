#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int& i:a) cin >> i;
  for(int& i:b) cin >> i;
  int ans = 2;
  for (int i=1;i<n;i++) {
    if (min(a[i], b[i]) >= max(a[i-1], b[i-1])) ans*=2;
    ans %= mod;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}