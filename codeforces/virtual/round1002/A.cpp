#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int& i:a) cin >> i;
  for(int& i:b) cin >> i;
  int x = 0;
  set<int> s;
  for(int i:a) s.insert(i);
  x = s.size();
  s.clear();
  for (int i:b) s.insert(i);
  int y = s.size();
  x *= y;
  if (x<=2) cout<<"NO\n";
  else cout<<"YES\n";
}
int main() {
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}