#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
int vs[N];
vector<int> g[N],h[N];
vector<pair<int,int>> ans;
set<pair<int,int>> s;
void dfs(int u, int ant) {
  vs[u] = 1;
  for (int v : g[u]) {
    if (s.count({u, v})==0) {
      ans.push_back({u,v});
      s.insert({u, v});
      s.insert({v, u});
    }
    if (vs[v]==0) {
      dfs(v,u);
    }
  }
}
void dfs2(int u) {
  vs[u] = 1;
  for (int v : h[u]) {
    if (vs[v]==0) {
      dfs2(v);
    } else {
    }
  }
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
  dfs(1,1);
  for (auto u : ans) h[u.S].push_back(u.F);
  for (int i=1;i<=n;i++) vs[i] = 0;
  dfs2(1);
  for (int i=1;i<=n;i++) if (!vs[i]) {
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  for (auto u : ans) {
    cout<<u.F<<" "<<u.S<<"\n";
  }
}