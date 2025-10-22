#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll m[20000005],f[20000005];

void solve() {
  int c,d,x;
  cin >> c >> d >> x;
  int p = 1;
  ll ans = 0;
  for  (int i=1;i*i<=x;i++) {
    if (x%i!=0) continue;
    int y = x/i + d;
    if (y % c == 0) ans += (1<<f[y/c]);
    if (i*i==x) continue;
    int z = i+d;
    if (z%c==0) ans += (1<<f[z/c]);
  }
  cout << ans << "\n";
}

int numOfPrimes(int u) {
  int cnt = 0;
  for (int i=2;i*i<=u;i++) {
    if (u%i==0) {
      cnt++;
      while (u%i==0) u /= i;
    }
  }
  if (u>1) cnt++;
  return cnt;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  m[1] = 1;
  for (int i=2;i<=20000000;i++) m[i] = -1;
  for (int i=2;i<=20000000;i++) if (m[i] == -1) 
    for (int j=i;j<=20000000;j+=i) if (m[j] == -1) m[j] = i;
  for (int i=2;i<=20000000;i++) {
    int j = i/m[i];
    f[i] = f[j] + (m[i] != m[j]);
  }
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}