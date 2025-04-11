#include <bits/stdc++.h>
using namespace std;
vector<int> g[2005];
const int mod = 1e9+7;

bool check(int n, int p) {
  vector<int> aux(n);
  for (int j=0;j<n;j++) {
    if (p & (1<<j)) {
      aux[j] = 1;
    }
  }
  int prev = -1;
  for (int j=0;j<n;j++) if (aux[j] == 1) {
    if ((j-prev)%2==0) {
      return false;
    } 
    prev = j;
  }
  if ((n-prev)%2==0) {
    return false;
  }
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(m + 1, vector<int>(1<<n, 0));
  for (int i=0;i<(1<<n);i++) {
    dp[0][i] = 1;
    vector<int> aux(n);
    for (int j=0;j<n;j++) {
      if (i & (1<<j)) {
        aux[j] = 1;
      }
    }
    int prev = -1;
    for (int j=0;j<n;j++) if (aux[j] == 1) {
      if ((j-prev)%2==0) {
        dp[0][i] = 0;
        j=n;
      }
      prev = j;
    }
    if ((n-prev)%2==0) {
      dp[0][i] = 0;
    }
  }
  int cnt = 0;
  for (int i=0;i<(1<<n);i++) {
    for (int j=0;j<(1<<n);j++) {
      if ((i & j) == 0) {
        int  p = i+j;
        if (check(n, p)) g[i].push_back(j);

      }
    }
  }
  for (int i=1;i<=m;i++) for (int j=0;j<(1<<n);j++) {
    for (int k=0;k<g[j].size();k++) {
      dp[i][j] += dp[i-1][g[j][k]];
      dp[i][j] %= mod;
    }
  }
  cout << dp[m-1][0]<<endl;
  return 0;
}