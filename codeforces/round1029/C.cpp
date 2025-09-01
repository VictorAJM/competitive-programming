#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  map<int,int> m;
  int diffs = 0;
  for (int i=0;i<n;i++) {
    m[a[i]]++;
    if (m[a[i]]==1) diffs++;
  }
  set<int> s;
  int cnt = 0;
  for (int i=n-1;i>=0;) {
    int _diffs = diffs;
    s.clear();
    while (s.size()<_diffs) {
      s.insert(a[i]);
      m[a[i]]--;
      if (m[a[i]]==0) diffs--;
      i--;
    }
    cnt++;
  }
  cout << cnt << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}