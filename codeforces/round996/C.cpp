#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
long long a[1005][1005];
long long vs[1005],hs[1005];
set<long long> v[1005],h[1005];
void solve() {
  int n,m;
  cin >> n >> m;
  for (int i=0;i<=n;i++) h[i].clear();
  for (int i=0;i<=m;i++) v[i].clear();
  for (int i=0;i<=n;i++) hs[i] = 0;
  for (int i=0;i<=m;i++) vs[i] = 0;
  string s;
  cin >> s;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
  long long sum = 0;
  if (s[0]=='R') {
    for (int i=0;i<n;i++) sum += a[i][0];
  } else {
    for (int i=0;i<m;i++) sum += a[0][i];
  }
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) hs[i]+=a[i][j];
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) vs[j]+=a[i][j];
  int x=0;
  int y=0;
  for (auto u : s) {
    if (u=='D') {
      a[x][y] = -hs[x];
      hs[x] += a[x][y];
      vs[y]+=a[x][y];
      x++;
    } else {
      a[x][y] = -vs[y];
      vs[y] += a[x][y];
      hs[x] += a[x][y];
      y++;
    }
  }
  a[n-1][m-1] =- vs[m-1];
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) cout<<a[i][j] <<" ";
    cout<<"\n";
  }
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}