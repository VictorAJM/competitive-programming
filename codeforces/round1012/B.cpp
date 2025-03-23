#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
char a[55][55];
int le[55], co[55];
void solve() {
  int n,m;
  cin>>n>>m;
  for (int i=1;i<=n;i++) a[i][0]='1', le[i]=1;
  for (int i=1;i<=m;i++) a[0][i]='1', co[i]=1;
  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j];
  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (a[i][j]=='1') {
    if (!(le[i] || co[j])) {
      cout<<"NO\n";
      return;
    }
  } else {
    le[i] = 0;
    co[j]=0;
  }
  cout<<"YES\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}