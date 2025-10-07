#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n%2==0) {
    cout<<"-1\n";
    return;
  }
  for (int i=1;i<=n;i+=2) cout << i << " ";
  for (int i=2;i<=n;i+=2) cout<<i<<" ";
  cout<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}