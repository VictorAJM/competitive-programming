#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for (int& i:a) cin >> i;
  for (int& i:b) cin >> i;
  int ans = a[n-1];
  for (int i=0;i<n-1;i++) if (a[i] > b[i+1]) ans += a[i]- b[i+1];
  cout << ans << "\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}