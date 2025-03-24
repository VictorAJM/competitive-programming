#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 1e5+5;
using ii = pair<int,int>;
map<int,int> c[N], t[N];
int a[N];
vector<ii> q[N];
vector<int> g[N];
bool vs[N];
int cnt[N];
int ans[N],n,m;
void dfs(int u) {
  vs[u] = 1;
  c[u][a[u]]=1;
  t[u][1]=1;
  cnt[u]=1;
  for (auto v : g[u]) if (!vs[v]) {
    dfs(v);
    if (cnt[u]<cnt[v]) {
      c[u].swap(c[v]);
      t[u].swap(t[v]);
      
    }


    for (auto w : c[v]) {
      int p = c[u][w.F];
      for (int i=1;i<=w.S;i++) t[u][p+i]++;
    }
    for (auto w : c[v]) c[u][w.F]+=w.S;
    cnt[u]+=cnt[v];
  }
  for (auto v : q[u]) {
    ans[v.S] = t[u][v.F];
  }
}
int main() {
  cin >> n >> m;
  for (int i=1;i<=n;i++) cin >> a[i];
  for (int i=1;i<n;i++) {
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i=0;i<m;i++) {
    int u,v;
    cin >> u >> v;
    q[u].push_back({v, i});
  }
  dfs(1);

  for (int i=0;i<m;i++)  cout << ans[i] << "\n";
}