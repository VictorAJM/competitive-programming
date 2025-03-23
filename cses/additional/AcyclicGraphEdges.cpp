#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
int vs[N];
vector<int> g[N];
vector<pair<int,int>> ans;
void dfs(int u) {
  vs[u] = 1;
  for (int v : g[u]) {
    if (vs[v]==0) {
      ans.push_back({u,v});
      dfs(v);
    } else if (vs[v]==1) {
      
    } else {
      ans.push_back({u, v});
    }
  }
  vs[u] = 2;
}
int main() {
  int n,m;
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i=1;i<=n;i++) if (!vs[i]) dfs(i);
  for (auto u : ans) cout<<u.F << " "<<u.S<<"\n";
}