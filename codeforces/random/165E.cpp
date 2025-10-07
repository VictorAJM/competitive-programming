#include <bits/stdc++.h>
using namespace std;
int n,a[1000005];
int dp[4500005],s[4500005];
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) cin >> a[i];
  for (int i=1;i<=n;i++) s[a[i]]=1;
  for (int i=0;i<(1<<22);i++) {
    dp[i] = -1;
    if (s[i]) dp[i] = i;
    for (int j=0;j<22;j++) if ((i&(1<<j))>0) {
      dp[i] = max(dp[i], dp[i-(1<<j)]);
    }
  }
  for (int i=1;i<=n;i++) {
    int y = (1<<22)-1-a[i];
    cout<<dp[y]<<" ";
  }
}