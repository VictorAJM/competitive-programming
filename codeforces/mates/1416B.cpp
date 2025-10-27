#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  int s = 0;
  for (int i:a) s += i;
  if (s%n!=0) {
    cout << "-1\n";
    return;
  }

  s /= n;

  vector<int> pending;
  vector<pair<int,pair<int,int>>> ans;

  for (int i=2;i<=n;i++) {
    int c = a[i-1]%i;
    c = i-c;
    c %= i;
    if (c>0) {
      ans.push_back({1, {i, c}});
      a[i-1] += c;
      a[0] -= c;
    }
    ans.push_back({i, {1, a[i-1]/i}});
    a[0] += a[i-1];
    a[i-1] = 0;
  }
  for (int u=2;u<=n;u++) {
    ans.push_back({1, {u, s}});
    a[0] -= s;
    a[u-1] += s;
  }
  cout << ans.size() << "\n";
  for (auto u : ans) {
    cout << u.F << " "<<u.S.F << " "<<u.S.S << "\n";
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}