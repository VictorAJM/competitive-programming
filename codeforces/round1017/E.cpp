#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> z(35);
  for(int& i:a) cin >> i;
  long long ans = 0;
  for (int i=0;i<30;i++) {
    long long x=0;
    long long y=0;
    for (auto u : a) {
      if ((u&(1<<i))) z[i]++;
    }
  }

  for (int i=0;i<n;i++) {
    long long p = a[i];
    long long cur = 0;
    for (int j=0;j<30;j++) {
      if (p&(1<<j)) cur += (1ll<<j)*(n-z[j]);
      else cur += (1ll<<j)* z[j];
    }
    ans = max(ans,cur);
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