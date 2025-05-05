#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void solve() {
  int n;
  cin >> n;
  int ans=0;
  for (int i=1;i<=n;i++) ans += abs((n-i+1)-i);
  cout << ans/2+1<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}