#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  set<int> s;
  vector<int> a(n);  
  for (int& i:a) cin >> i;
  vector<int> b;
  for (int i:a) {
    if (s.count(i)==0) b.push_back(i);
    s.insert(i);
  }
  for (int i:b) cout<<i << " ";
  for (int i=1;i<=n;i++) if (s.count(i)==0) cout<<i<<" ";
  cout << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}