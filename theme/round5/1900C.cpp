#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 3e5+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

vector<int> g[N];
bool leaf[N];
string s;
int dfs(int u) {
  if (u==0) return mod;
  if (leaf[u]) return 0;
  if (s[u-1]=='U') return min(dfs(g[u][0])+1, dfs(g[u][1])+1);
  if (s[u-1]=='L') return min(dfs(g[u][0]), dfs(g[u][1])+1);
  if (s[u-1]=='R') return min(dfs(g[u][0])+1, dfs(g[u][1]));
}

void solve() {
  int n;
  cin >> n;
  cin >> s;
  for (int i=1;i<=n;i++) {
    g[i].clear();
    int x,y;
    cin >> x >> y;
    g[i].push_back(x);
    g[i].push_back(y);
    if (x+y==0) leaf[i] = 1;
    else leaf[i]=0;
  }
  cout << dfs(1) << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}