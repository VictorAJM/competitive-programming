#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
int main() {
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i=0;i<n;i++){
    cin >> a[i];
  }
  vector<pi> dp((1<<n), {INT_MAX, INT_MAX});
  dp[0] = {0, x+1};
  for (int i=1;i<(1<<n);i++) {
    int sum = x, cnt = n+1;
    dp[i] = {n, x};
    for (int j=0;j<n;j++){
      if (i & (1<<j)){
        dp[i] = min(dp[i], {dp[i^(1<<j)].first+1, a[j]});
      }
    }
    for (int j=0;j<n;j++){
      if (i & (1<<j)){
        if (a[j]+dp[i^(1<<j)].second <= x){
          if (dp[i^(1<<j)].first < cnt){
            cnt = dp[i^(1<<j)].first;
            sum = dp[i^(1<<j)].second + a[j];
          } else if (dp[i^(1<<j)].first == cnt){
            sum = min(sum, dp[i^(1<<j)].second + a[j]);
          }
        } 
      }
    }
    if (cnt < dp[i].first){
      dp[i] = {cnt, sum};
    } else if (cnt == dp[i].first){
      dp[i].second = min(dp[i].second, sum);
    }
  }
  cout << dp[(1<<n)-1].first << "\n";
}