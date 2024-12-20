#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 205;
const ll inf = 1e18;
ll a[N][N],dp[N][N],f[N][N][N];

void solve() {
  ll n,m,k;
  cin>>n>>m>>k;
  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j];

  for (int i=1;i<=n+1;i++) for (int j=1;j<=m;j++) dp[i][j] = inf;
  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
    f[i][j][0] = 0;
    for (int q=1;q<=m;q++) {
      int p = q+j-1;
      if (p>m) p-=m;
      f[i][j][q] = f[i][j][q-1] + a[i][p];
    }
  }
  dp[n+1][m] = 0;
  for (int i=n;i>=1;i--) for (int j=m;j>=1;j--) {
    for (int q=j;q<=m;q++) {
      ll costo = inf;
      for (int kk=1;kk<=m;kk++) {
        ll z = kk-j;
        if (z<0) z+=m;
        z*=k;
        z+=f[i][kk][q-j+1];
        costo = min(costo, z);
      }
      dp[i][j] = min(dp[i][j], dp[i+1][q]+costo);
    }
  }
  cout<<dp[1][1]<<"\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}