#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 2e3+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using i3 = pair<int,ii>;
using vi = vector<int>;

int ans[N][N],vs[N][N];
void solve() {
  int n;
  cin >> n;
  queue<ii> q;
  int cnt=0;
  int p = n%2;
  q.push({n/2+p,n/2+p});
  for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) vs[i][j]=0;
  vs[n/2+p][n/2+p]=1;
  ans[n/2+p][n/2+p]=0;
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    if (x.F>1 && !vs[x.F-1][x.S]) {
      q.push({x.F-1,x.S});
      vs[x.F-1][x.S]=1;
      ans[x.F-1][x.S]=++cnt;
    }
    if (x.F>1 && x.S<n && !vs[x.F-1][x.S+1]) {
      q.push({x.F-1,x.S+1});
      vs[x.F-1][x.S+1]=1;
      ans[x.F-1][x.S+1]=++cnt;
    }
    if (x.S<n && !vs[x.F][x.S+1]) {
      q.push({x.F,x.S+1});
      vs[x.F][x.S+1]=1;
      ans[x.F][x.S+1]=++cnt;
    }
    if (x.F<n && x.S<n && !vs[x.F+1][x.S+1]) {
      q.push({x.F+1,x.S+1});
      vs[x.F+1][x.S+1]=1;
      ans[x.F+1][x.S+1]=++cnt;
    }
    if (x.F<n && !vs[x.F+1][x.S]) {
      q.push({x.F+1,x.S});
      vs[x.F+1][x.S]=1;
      ans[x.F+1][x.S]=++cnt;
    }
    if (x.F<n && x.S>1 && !vs[x.F+1][x.S-1]) {
      q.push({x.F+1,x.S-1});
      vs[x.F+1][x.S-1]=1;
      ans[x.F+1][x.S-1]=++cnt;
    }
    if (x.S>1 && !vs[x.F][x.S-1]) {
      q.push({x.F,x.S-1});
      vs[x.F][x.S-1]=1;
      ans[x.F][x.S-1]=++cnt;
    }
    if (x.F>1 && x.S>1 && !vs[x.F-1][x.S-1]) {
      q.push({x.F-1,x.S-1});
      vs[x.F-1][x.S-1]=1;
      ans[x.F-1][x.S-1]=++cnt;
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) cout << ans[i][j] << " ";
    cout << "\n";
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}