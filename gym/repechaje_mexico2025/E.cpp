#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 1e5+5;
set<pair<int,int>> s;
bool vs[N];
vector<int> g[N];
vector<pair<int,int>> ans;
void dfs(int u) {
  vs[u] = 1;
  for (int v : g[u]) if (!vs[v]) {
    ans.push_back({u,v});
    dfs(v);
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  for (int i=1;i<=m;i++) {
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    s.insert({u,v});
  }
  dfs(1);

  if (ans.size()==m) {
    cout << "*\n";
    return 0;
  }

  for (auto u : ans) {
    if (s.count(u)) cout << u.F <<" "<<u.S << "\n";
    else cout << u.S << " "<<u.F<<"\n";
  }
}