#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int j=0;
  char x='1';
  char y='0';
  int cnt = 0;
  while (j<n) {
    if (s[j]==x) {
      cnt++;
      while (j<n && s[j]==x) j++;
      swap(x, y);
    } else {
      while (j<n && s[j]==y) j++;
    }
  }
  cout << cnt << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}