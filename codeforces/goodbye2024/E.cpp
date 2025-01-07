#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
using ll = long long;
ll vis[N],dist[N],mayor[N],total, hojas, hoja[N],curTotal[N];
vector<ll> g[N];
void dfs(int node, int h) {
  vis[node] = 1;
  hoja[node] = 1;
  for (auto u : g[node]) if (!vis[u]) {
    dfs(u, h);
    hoja[node] = 0;
  }
  if (hoja[node]) hojas++;
}
void dfs1(int node) {
  vis[node] = 1;
  if (dist[node]>1) total++;
  if (dist[node]>1) curTotal[node]++;
  for (auto u : g[node]) if (!vis[u]) {
    dfs1(u);
    curTotal[node] += curTotal[u];
  }
}
void dfs2(int no, ll& ans) {
  vis[no] =1;
  if (dist[no] == 1) {
    // for each non zero, ans += total-curtotal;
    for (auto u : g[no]) if (!vis[u]) if (dist[u]>0) ans+=total-curTotal[u];
  }
  if (dist[no]>0) for (auto u : g[no]) if (!vis[u]) if (dist[u]==1) ans+=curTotal[u];
  for (auto u : g[no]) if (!vis[u]) dfs2(u, ans);
}
void solve() {
  ll n;
  cin>>n;
  for (int i=1;i<=n;i++) {
    vis[i] = 0;
    g[i].clear();
    dist[i] = 0;
    mayor[i] = 0;
    total = 0;
    hojas = 0;
    hoja[i] = 0;
    curTotal[i] = 0;
  }
  for (int i=1;i<n;i++) {
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0); 
  if (g[1].size()==1) {
    hoja[1] = 1;
    hojas++;
  }
  long long ans = 0;
  queue<pair<int,int>> q;
  for (int i=1;i<=n;i++) if (hoja[i]) q.push({i,0});
  for (int i=1;i<=n;i++) vis[i] = 0;
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (vis[v.first]) continue;
    vis[v.first] = 1;
    dist[v.first] = v.second;
    for (auto u : g[v.first]) if (!vis[u]) {
      q.push({u, v.second+1});
    }
  }

  for (int i=1;i<=n;i++) vis[i] = 0;
  dfs1(1);
  for (int i=1;i<=n;i++) vis[i] = 0;
  dfs2(1, ans);
  ans += hojas*(n-hojas);
  cout<<ans << "\n";
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}