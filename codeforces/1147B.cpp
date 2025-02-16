#include <bits/stdc++.h>
using namespace std;
vector<int> KMP(vector<vector<int>> a) {
  int n = a.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for(int i = 1; i < n; i++) {
      if(i < r) {
          z[i] = min(r - i, z[i - l]);
      }
      while(i + z[i] < n && a[z[i]] == a[i + z[i]]) {
          z[i]++;
      }
      if(i + z[i] > r) {
          l = i;
          r = i + z[i];
      }
  }
  return z;

}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> b(m);
  for (auto& i:b) cin >> i.first >> i.second;
  vector<vector<int>> a(n);
  for (auto i : b) a[i.first-1].push_back((n+i.second-i.first)%n), a[i.second-1].push_back((n+i.first-i.second)%n);
  for (int i=0;i<n;i++) sort(a[i].begin(), a[i].end());
  for (int i=0;i<n;i++) a.push_back(a[i]);
  vector<int> ans = KMP(a);
  bool t = false;
  for (int i=0;i<n;i++) if (ans[i]>=n) t = true;
  cout << (t ? "YES" : "NO");
  return 0;
}