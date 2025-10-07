#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
ll dp[2][5005];
ll m2[5005];
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i=0;i<n;i++) cin >> a[i];
  set<ll> st;
  for (auto u : a) st.insert(u);
  int cnt = 0;
  for (auto u : st) {
    cnt++;
    m2[cnt] = u;
  }
  dp[0][0] = inf;
  for (int j=1;j<=cnt;j++) dp[0][j] = min(abs(m2[j] - a[0]), dp[0][j-1]);
  for (int i=1;i<n;i++) {
    dp[1][0] = inf;
    for (int j=1;j<=cnt;j++) {
      dp[1][j] = inf;
      if (j) dp[1][j] = min(dp[0][j]+abs(m2[j] - a[i]), dp[1][j-1]);
      else dp[1][j] = dp[0][j] + abs(m2[j]-a[i]);
    }
    for (int j=0;j<=cnt;j++) dp[0][j] = dp[1][j];
  }
  cout << dp[1][cnt] <<endl;
}