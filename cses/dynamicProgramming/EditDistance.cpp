#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  string a,b;
  cin >> a >> b;
  n = a.size();
  m = b.size();
  
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
  
  dp[0][0] = 0;
  for (int i=1;i<=n;i++){
    dp[i][0] = i;
  }
  for (int j=1;j<=m;j++){
    dp[0][j] = j;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1, dp[i - 1][j - 1]});
      } else {
        dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
      }
    }
  }
  
  cout << dp[n][m] << "\n";
  
  return 0;
}