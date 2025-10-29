#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int N = 2e5+5;

using ll = long long;
using ii = pair<ll,ll>;

ll n, vs[N], val[N], a[N], b[N], c[N], hei[N], dp[N][22], tam[N];
vector<int> g[N];

ll ans;

ii dfs(ll u, ll m) {
  vs[u] = 1;
  ii aa = {0, 0};
  if (b[u] != c[u]) {
    if (b[u] == 0) aa.S++;
    else aa.F++;
  }
  for (auto v : g[u]) if (!vs[v]) {
    ii aux =  dfs(v, min(m, a[u]));
    aa.F += aux.F;
    aa.S += aux.S;
  }
  if (a[u] < m) {
    ll z = min(aa.F, aa.S);
    ans += 2*z*a[u];
    aa.F -= z;
    aa.S -= z;
  }
  return aa;
}

int main() {
  cin >> n;

  int x=0, y=0;
  for (int i=1;i<=n;i++) {
    cin >> a[i] >> b[i] >> c[i];
    if (b[i]) x++;
    if (c[i]) y++;
  }

  if (x != y) {
    cout << "-1\n";
    return 0;
  }

  for (int i=0;i<n-1;i++) {
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  

  dfs(1, 1e9);

  cout << ans << "\n";
  
  return 0;
}