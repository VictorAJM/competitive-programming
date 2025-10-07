#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

using ll = long long;

ll n;
vector<ll> g[N];
ll ans[N];
ll dp[N];
ll tam[N];
bool vs[N];

void dfs(int u, int depth = 0) {
  vs[u] = 1;
  tam[u] = 1;
  for (auto v : g[u]) if (!vs[v]) {
    dfs(v, depth+1);
    tam[u] += tam[v];
    dp[u] += dp[v];
  }
  dp[u] += tam[u];
}

void dfs2(int u) {
  vs[u] = 1;
  for (auto v : g[u]) if (!vs[v]) {
    ans[v] = ans[u] + (n-tam[v]) - tam[v];
    dfs2(v);
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for (ll i=1;i<n;i++) {
    ll u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1);

  for (int i=1;i<=n;i++) vs[i] = 0;
  ans[1] = dp[1];
  dfs2(1);

  cout << *max_element(ans+1, ans+n+1) << "\n";

}