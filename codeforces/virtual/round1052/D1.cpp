#include <bits/stdc++.h>
using namespace std;

void f(int r, vector<int>& ans) {
  if (r<0) return;
  int p = 1;
  while (p <= r) p*=2;
  int q = p/2;
  p--;
  int gg = p-r-1;
  while (r>=q) {
    ans[p-r] = r;
    ans[r] = p-r;
    r--;
  }
  f(gg, ans);
}

void solve() {
  int l,r;
  cin >> l >> r;
  // l = 0
  vector<int> ans(r+1);
  f(r, ans);
  long long ANS = 0;
  for (int i=0;i<=r;i++) {
    ANS += i|ans[i];
  }
  cout << ANS << "\n";
  for (auto u : ans) cout << u << " ";
  cout << "\n";
 }

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}