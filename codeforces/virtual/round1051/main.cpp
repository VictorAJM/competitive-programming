#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int N = 305;
const int mod = 1e9+7;
using ll = long long;


ll dp[N][N][N];
ll dp2[N][N][N];



void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  
  for (int i=0;i<=n+1;i++) for (int j=i;j<=n+1;j++) dp[n][i][j] = 1;
  for (int k=n-1;k>=0 ;k--) for (int j=n;j>=1;j--) for (int i=j;i>=1;i--) {
    dp[k][i][j] = 0;
    ll z = 0;
    if (a[k] <= j && a[k] >= i) z = dp[k+1][a[k]][j];
    dp[k][i][j] = dp[k+1][i][j] + z;
    dp[k][i][j] %= mod;
  }

  ll ans = 0;
  for (int i=0;i<n;i++) {
    long long mayor = dp[i+1][a[i]+1][n];
    long long menor = dp[i+1][1][a[i]-1];

    long long mayor2 = dp[i+1][a[i]][n];
    long long menor2 = dp[i+1][1][a[i]];
    ll x,y,q,w;
    q = mayor;
    w = menor;
    x = mayor2;
    y = menor2;
    x *= y;
    x%=mod;
    ans -= x;
        if (ans < 0) ans += mod;
    ans %= mod;
    q*=w;
    q%=mod;
    ans += q;
    ans%=mod;

    cerr << mayor << " "<<menor << "\n";
    mayor *= menor2;
    mayor2 *= menor2;
    mayor%= mod;
    mayor2 %= mod;
    ans += mayor;
    ans += mayor2;
   ans %= mod;
   if (ans < 0) ans+=mod;
   ans%=mod;
  }
  cerr<<"\n";
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}