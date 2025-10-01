#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[1005][1005];
bool vs[1005][1005];

int DP(int x, int y, vector<int>& a, vector<int>& b) {
  if (x == n) return 0;
  if (y == m) return 0;

  if (vs[x][y]) return dp[x][y];
  vs[x][y] = 1;

  if (a[x] == b[y]) {
    dp[x][y] = max({1 + DP(x+1, y+1, a, b), DP(x+1, y, a, b), DP(x, y+1, a, b)});
    return dp[x][y];
  }
  dp[x][y] = max(DP(x+1, y, a, b), DP(x, y+1, a, b));
  return dp[x][y];
} 

int main() {
  cin >>  n >> m;
  vector<int> a(n), b(m);
  for(int& i:a) cin >> i;
  for(int& i:b) cin >> i;

  DP(0, 0, a, b);
  cout << dp[0][0] << "\n";
  int p = dp[0][0];
  int x = 0;
  int y = 0;
  while (p > 0) {
    if (a[x] == b[y] && dp[x+1][y+1] == p-1) {
      cout << a[x] <<" ";
      x++; y++; p--;
    } else if (dp[x+1][y] == p) {
      x++;
    } else {
      y++;
    }
  }
  return 0;
}