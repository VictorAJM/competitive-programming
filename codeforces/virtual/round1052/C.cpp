#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ans;
  vector<int> prev;
  int cnt =0;
  int x=1;
  for (int i=0;i<n;i++) {
    if (s[i]=='1') {
      if (cnt==1) {
        cout << "NO\n";
        return;
      }
      if (cnt>0) {
      for (int j=1;j<prev.size();j++) {
        ans.push_back(prev[j]);
      }
      ans.push_back(prev[0]);
    }
      prev.clear();
      ans.push_back(x++);
      cnt=0;
    } else {
      cnt++;
      prev.push_back(x++);
    }
  }
  if (cnt==1) {
    cout << "NO\n";
    return;
  }
  if (cnt>0) {
  for (int j=1;j<prev.size();j++) {
    ans.push_back(prev[j]);
  }
  ans.push_back(prev[0]);
}
  cout <<"YES\n";
  for (auto u : ans) cout << u << " ";
  cout<<"\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}