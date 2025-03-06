#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll cnt = 0;
  ll x = 0, y = 0;
  for (int i=0;i<n;i++) if (s[i] == '-') x++;
  cnt = (n-x)*(x/2)*(x/2 + x%2);
  cout << cnt << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}