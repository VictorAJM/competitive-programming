#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
ll dp[200005], aux[200005], cur[200005], ans[200005];
int main() {
  int n,k;
  cin >> n >> k;
  int l = k; int r = k;
  int s = k;
  while (s <= n) {
    r++;
    s += r;
  }
  dp[0]=1;
  for (int i=l;i<r;i++) {
    for (int j=0;j<=n;j++) {
      int m = j; m%=i;
      
      aux[j] = cur[m];
      cur[m] += dp[j]; cur[m] %= mod;
    }
    for (int j=0;j<=n;j++) {
      dp[j] = aux[j]; aux[j] = 0;
      ans[j] += dp[j]; ans[j] %= mod;
    }
   
    for (int j=0;j<=i;j++) cur[j] = 0;
  }
  for (int i=1;i<=n;i++) cout << ans[i] << " ";
  return 0;
}