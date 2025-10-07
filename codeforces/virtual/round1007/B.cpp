#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  set<int> s = {1, 8, 49, 288, 1681, 9800, 57121, 332928};
  if (s.count(n)) {
    cout<<"-1\n";
    return;
  }
  for (int i=1;i<=n;i++) if (s.count(i)) {
    cout<<i+1 << " "<<i<<" ";
    i++;
  } else {
    cout<<i << " ";
  }
  cout << "\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}