#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 4e5+5;
set<pair<int,int>> s,_s;
vector<int> g[N],h[N];
int _u[N],_v[N];
bool vs[N];
void dfs(int u) {
  vs[u] = 1;
  for (auto v : g[u]) {
    if (s.count({u,v})==0) {
      s.insert({u,v});
      s.insert({v,u});
      _s.insert({u,v});
    }
    if (!vs[v]) dfs(v);
  }
}
void _dfs(int u) {
  vs[u] = 1;
  for (auto v : h[u]) {
    if (!vs[v]) _dfs(v);
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  for (int i=0;i<m;i++) cin >> _u[i] >> _v[i];
  for (int i=0;i<m;i++) {
    g[_u[i]].push_back(_v[i]);
    g[_v[i]].push_back(_u[i]);
  }
  dfs(1);
  for (auto u : _s) h[u.S].push_back(u.F);
  for (int i=1;i<=n;i++) vs[i] = 0;
  _dfs(1);
  for (int i=1;i<=n;i++) if (!vs[i]) {
    cout<<"0\n";
    return 0;
  }
  for (auto u : _s) cout<<u.F << " "<<u.S<<"\n";
  return 0;
}