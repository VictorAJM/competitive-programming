#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  set<char> _s;
  for (int i=1;i<n-1;i++) {
    if (s[i]=='.') continue;
    _s.insert(s[i]);
  }
  if (_s.size()>=2) {
    cout<<"NO\n";
    return;
  }
  int j=0;
  while (j<n && s[j]!='p') j++;
  while (j<n && s[j]!='s') j++;
  if (j==n) cout<<"YES\n";
  else cout<<"NO\n";
}
int main() {
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}