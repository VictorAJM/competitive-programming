#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll f[105];

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  f[0] = f[1] = 1;
  for (int i=2;i<=100;i++) f[i] = f[i-1]+f[i-2];
  int t;
  cin >> t;
  while (t--) {
    ll x,k;
    cin >> x >> k;
    int _ = 1;
    while (f[_]*x < k) _++;
    cout << _ << "\n";
  }
  return 0;
}