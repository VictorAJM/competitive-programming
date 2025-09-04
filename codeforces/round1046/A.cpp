#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

using ll = long long;

void solve() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if (max(a,b) > 2*min(a,b)+2) {
    cout << "NO\n";
    return;
  }
  c -= a; d -= b;
  if (max(c,d) > 2*min(c,d) + 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}