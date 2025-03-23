#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[300005][505];
const int mod = 1e9+7;
int main() {
  int n,k;
  cin >> n >> k;
  dp[0][1]=1;
  for (int i=2;i<=n;i++) {
    ll ans = 0;
    ll r = i*(i-1);
    r /=2;
    for (int j=0;j<=r;j++) {
      if (j-i>=0) {
        ans -= dp[j-i][i-1];
        if (ans<0) ans+=mod;
      }
      ans+=dp[j][i-1];
      ans%=mod;
      dp[j][i] = ans;
    }
  }
  cout << dp[k][n];
  return 0;
}