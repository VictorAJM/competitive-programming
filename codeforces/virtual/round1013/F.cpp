#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2005;
const int mod  = 998244353;
ll dp[N][N][2];
char a[N][N];
ll f[N];
void solve() {
  int n,m,d;
  cin >> n >> m >> d;
  int x = sqrt(d*d-1);
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
  for (int i=0;i<m;i++) {
    if (a[0][i]=='X') dp[0][i][0]=1;
    else dp[0][i][0]=0;
  }
  for (int i=0;i<n;i++) {
    if (i>0) {
      f[0]=dp[i-1][0][1];
      for (int j=1;j<m;j++) {
        f[j]=dp[i-1][j][1]+f[j-1];
        f[j]%=mod;
      }
      // dp en 0
      
      for (int j=0;j<m;j++) {
        int y = f[min(m-1,j+x)];
        if (j-x>0) y -= f[j-x-1];
        y%=mod;
        if (y<0) y+=mod;
        if (a[i][j]=='X')
        dp[i][j][0]=y;
        else dp[i][j][0]=0;
      }
    }

    f[0]=dp[i][0][0];
    for (int j=1;j<m;j++) {
      f[j]=dp[i][j][0]+f[j-1];
      f[j]%=mod;
    }
    // dp en 1
    for (int j=0;j<m;j++) {
      int y = f[min(m-1,j+d)];
      if (j-d>0) y -= f[j-d-1];
      y%=mod;
      if (y<0) y+=mod;
      if (a[i][j]=='X')
      dp[i][j][1]=y;
      else dp[i][j][1]=0;
    }

  }
  ll ans=0;
  for (int j=0;j<m;j++) {
    ans+=dp[n-1][j][1];
    ans%=mod;
  }
  cout<<ans<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}