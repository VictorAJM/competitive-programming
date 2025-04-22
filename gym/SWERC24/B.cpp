#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll dp[5005][25];
int g[5005][25];
const ll inf = 1e18;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n), ans(n+1);
  vector<pair<ll,int>> b(n);
  for (int i=0;i<n;i++) {
    cin >> a[i];
    b[i] = {a[i] , i};
  }
  sort(b.begin(), b.end());
  sort(a.begin(), a.end());
  dp[0][0] = inf;
  g[0][0] = -1;
  for (int i=1;i<=k;i++) {
    dp[0][i] = 0;
    g[0][i] = -1;
  }
  for (int i=1;i<n;i++) {
    dp[i][0] = inf;
    g[i][0] = -1;
    for (int j=1;j<=k;j++) {
      dp[i][j] = inf;
      g[i][j] = -1;
      ll cur = 0;
      for (int l=i-1;l>=0;l--) {
        if (dp[l][j-1] + cur < dp[i][j]) {
          g[i][j] = l;
          dp[i][j] = dp[l][j-1] + cur;
        }
        cur += (a[i] - a[l]) * (a[i] - a[l]);
      }
      if (cur < dp[i][j]) {
        g[i][j] = -1;
        dp[i][j] = cur;
      }
    }
  }
  int x = n-1, y = k;
  int j=n-1;
  while (x != -1) {
    while (j > g[x][y]) {
      ans[b[j].second] = a[x];
      j--;
    }
    x = g[x][y];
    y--;
  }
  for (int i=0;i<n;i++) {
    cout << ans[i] << " ";
  }
}