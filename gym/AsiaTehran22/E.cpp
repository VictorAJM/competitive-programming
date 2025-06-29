#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e3+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

int n,m;
char a[N][N];
int vis[N][N];

void solve() {
  cin >> n >> m;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (a[i][j]=='o') vis[i][j]=3;

  // horizontal
  for (int i=0;i<n;i++) {
    vi x;
    for (int j=0;j<m;j++) if (a[i][j]=='o') x.push_back(j);
    if (x.empty()) {
      for (int j=0;j<m;j++) vis[i][j]|=1;
    } else {
      for (int j=0;j<x[0];j++) vis[i][j]|=1;
      for (int j=x[x.size()-1]+1;j<m;j++) vis[i][j]|=1;
    }
  }

  // vertical
  for (int j=0;j<m;j++) {
    vi x;
    for (int i=0;i<n;i++) if (a[i][j]=='o') x.push_back(i);
    if (x.empty()) {
      for (int i=0;i<n;i++) vis[i][j]|=1;
    } else {
      for (int i=0;i<x[0];i++) vis[i][j]|=1;
      for (int i=x[x.size()-1]+1;i<n;i++) vis[i][j]|=1;
    }
  }

  int cnt = 0;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (vis[i][j]==1) cnt++;
  cout << cnt << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t=1;
  while (t--) solve();
  return 0;
}