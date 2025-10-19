#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
  string p = s;
  reverse(p.begin(), p.end());
  return s == p;
}

bool isDecreasing(string s) {
  for (int i=1;i<(int)s.size();i++) if (s[i]<s[i-1]) return false;
  return true;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ans;
  for (int i=1;i<=n;i++) ans.push_back(i);
  for (int i=0;i<(1<<n);i++) {
    string p;
    string q;
    for (int j=0;j<n;j++) if ((i&(1<<j)) > 0) p.push_back(s[j]); else q.push_back(s[j]);
    if (!isPalindrome(p) || !isDecreasing(q)) continue;
    vector<int> aux;
    for (int j=0;j<n;j++) if ((i&(1<<j)) == 0) aux.push_back(j+1);
    cout << aux.size() << "\n";
    for (auto u : aux) cout << u << " ";
    cout << "\n";
    return;
  }
  cout << "-1\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}