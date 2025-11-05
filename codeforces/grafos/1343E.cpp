#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
const int N = 2e5+5;
ll n,m,a,b,c,p[N],f[N];
bool vs[N];
vector<ll> g[N];

void bfs(int ini, vector<ll>& dist) {
  queue<pair<ll,ll>> q;
  q.push({ini, 0});
  vs[ini] = 1;
  dist[ini] = 0;
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    for (auto v : g[x.F]) if (!vs[v]) {
      q.push({v, x.S+1});
      vs[v] = 1;
      dist[v] = x.S+1;
    }
  }
  return;
}

void solve() {
  cin >> n >> m >> a >> b >> c;
  for (int i=0;i<m;i++) cin >> p[i];
  sort(p, p+m);
  f[0] = 0;
  for (int i=1;i<=m;i++) f[i] = f[i-1] + p[i-1];
  for (int i=1;i<=n;i++) g[i].clear();
  for (int i=0;i<m;i++) {
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<ll> distA(n+1, 0);
  for (int i=1;i<=n;i++) vs[i] = 0;
  bfs(a, distA);

  vector<ll> distB(n+1, 0);
  for (int i=1;i<=n;i++) vs[i] = 0;
  bfs(b, distB);

  vector<ll> distC(n+1, 0);
  for (int i=1;i<=n;i++) vs[i] = 0;
  bfs(c, distC);

  ll ans = 1e18;
  for (int i=1;i<=n;i++) {
    ll z = distA[i] + distB[i] + distC[i];
    if (z>m) continue;
    ans = min(ans, f[z] + f[distB[i]]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}