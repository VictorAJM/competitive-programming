#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  int x=0,y=0;
  for (auto u : s) {
    if (u=='0') x++;
    else if (u=='1') y++;
  }
  string ans(n,'+');

  for (int i=0;i<x;i++) ans[i] = '-';
  for (int i=n-y;i<n;i++) ans[i]='-';

  int z=0;
  for (auto u : s) if (u=='2') z++;

  if (x+y+z >= n) {
    for (int i=0;i<n;i++) ans[i] = '-';
    cout << ans << "\n";
    return;
  }
  for (int i=x,_z = z;_z>0;_z--,i++) {
    if (ans[i] != '-') ans[i] = '?';
  }
  for (int i=n-y-1,_z = z;_z>0;_z--,i--) {
    if (ans[i] != '-') ans[i] = '?';
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}