#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int,int> m;
  for (int i=0;i<n;i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  vector<int> a;
  for (auto u : m) a.push_back(u.second);
  sort(a.begin(),a.end());
  int p=0;
  for (int i=0;i<a.size();i++) {
    p = max(p, ((int)a.size()-i)*a[i]);
  } 
  cout << p << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}