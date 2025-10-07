#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  getline(cin, s);
  string ans;
  for (int i=0;i<s.size();i++) {
    if (s[i]==' ') continue;
    ans.push_back(s[i]);
    while (i<s.size() && s[i]!=' ') i++;
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
    string s;
  getline(cin, s);
  while (t--) solve();
  return 0;
}