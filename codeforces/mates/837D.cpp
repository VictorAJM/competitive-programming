#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[205][5205], aux[205][5205];
ll x[205], y[205];
int main() {
  int n,k;
  cin >> n >> k;
  vector<ll> a(n); 
  for(ll& i:a) cin >> i;
  for (int i=0;i<n;i++) {
    while (a[i]%2==0) {
      x[i]++;
      a[i]/=2;
    }
    while (a[i]%5==0) {
      y[i]++;
      a[i]/=5;
    }
  }

  memset(dp, -1, sizeof(dp));
  memset(aux, -1, sizeof(aux));
  dp[0][0] = 0;

  for (int i=0;i<n;i++) {
    for (int j=0;j<=n;j++) for (int q=0;q<=n*26;q++) if (dp[j][q] != -1) {
      
      if (j<n && q+y[i] <= 26*n) aux[j+1][q+y[i]] = max(aux[j+1][q+y[i]], dp[j][q]+x[i]);
      aux[j][q] = max(aux[j][q], dp[j][q]);
      
    }
    swap(dp, aux);
  }
  ll ans = 0;
  for (int i=0;i<=26*n;i++) if (dp[k][i] != -1) {
    ans = max(ans, min((ll)i, dp[k][i]));
  }
  cout << ans << "\n";
}