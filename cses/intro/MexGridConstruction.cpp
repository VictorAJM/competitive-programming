#include <bits/stdc++.h>
using namespace std;
int a[105][105];
void solve() {
  int n;
  cin >> n;
  for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
    set<int> s;
    for (int k=1;k<j;k++) s.insert(a[i][k]);
    for (int k=1;k<i;k++) s.insert(a[k][j]);
    int mex=0;
    while (s.count(mex)) mex++;
    a[i][j] = mex;
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) cout << a[i][j] << " ";
    cout << "\n";
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  solve();
  return 0;
}