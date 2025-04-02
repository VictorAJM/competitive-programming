#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
const int N = 62;
const ll inf = 1e18;
ll dp[N][N][N];
ll DP[N];
void solve() {
  ll x,y;
  string X, Y;
  cin >> x >> y;
  ll ans = inf;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if ((x >> i) == (y >> j)) ans = min(ans, dp[i][j][N-1]);
    }
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  DP[0]=1;
  for (int i=1;i<N;i++) DP[i] = DP[i-1]+DP[i-1];
  for (int i=0;i<N;i++) for (int j=0;j<N;j++) dp[i][j][0] = inf;
  dp[0][0][0] = 0;
  for (int k=1;k<N;k++) for (int i=0;i<N;i++) for (int j=0;j<N;j++) {
    dp[i][j][k] = inf;
    dp[i][j][k] = min(dp[i][j][k-1], dp[i][j][k]);
    if (i>=k) dp[i][j][k]=min(dp[i][j][k], dp[i-k][j][k-1]+DP[k]);
    if (j>=k) dp[i][j][k]=min(dp[i][j][k], dp[i][j-k][k-1]+DP[k]);
  }

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}