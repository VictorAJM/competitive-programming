#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

using ll = long long;
using ii = pair<ll,ll>;
using i3 = pair<ll,ii>;
const int N = 2e5+5;
ll n,m;
i3 ed[N], _ed[N];
ll dp[N][20], val[N][20],hei[N];
bool vs[N];
vector<ii> g[N];
struct UnionFind {
  int ran;
  int dad;
} uf[N];
int bus(int u) {
  if (uf[u].dad != u) uf[u].dad = bus(uf[u].dad);
  return uf[u].dad;
}
void unir(int u, int v) {
  u = bus(u); v = bus(v);
  if (u==v) return;
  if (uf[u].ran < uf[v].ran) {
    uf[u].dad = v;
  } else if (uf[v].ran < uf[u].ran) {
    uf[v].dad = u;
  } else {
    uf[u].dad = v;
    uf[v].ran++;
  }
}
void dfs(int no, int dad, int arriba, int altura) {

  dp[no][0] = dad;
  hei[no] = altura;
  val[no][0] = arriba;
  vs[no] = 1;
  altura++;
  for (int i=1;i<20;i++) {
    dp[no][i] = dp[dp[no][i-1]][i-1];
    val[no][i] = max(val[no][i-1], val[dp[no][i-1]][i-1]);
  }

  for (auto u : g[no]) if (!vs[u.F]) dfs(u.F,no, u.S, altura);
}
ll lca(int in, int fi) {
  if (hei[in]<hei[fi]) swap(in, fi);
  ll h = hei[in]-hei[fi];
  for (int i=0;i<20;i++) if ((h&(1<<i))>0) {
    in = dp[in][i];
  }
  if (in == fi) return in;
  for (int i=19;i>=0;i--) if (dp[in][i]!=dp[fi][i]) {
    in = dp[in][i];
    fi = dp[fi][i];
  }
  return dp[in][0];
}
ll maxPath(int in, int fi) {
  ll z = lca(in, fi);
  ll h = hei[in] - hei[z];
  ll ans = 0;
  for (int i=0;i<20;i++) if ((h&(1<<i))>0) {
    ans = max(ans, val[in][i]);
    in = dp[in][i];
  }
  h = hei[fi] - hei[z];

  for (int i=0;i<20;i++) if ((h&(1<<i))>0) {
    ans = max(ans, val[fi][i]);
    fi = dp[fi][i];
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i=0;i<m;i++) cin >> ed[i].S.F >> ed[i].S.S >> ed[i].F;
  for (int i=0;i<m;i++) _ed[i] = ed[i];
  sort(_ed, _ed + m);
  for (int i=1;i<=n;i++) {
    uf[i].ran = 1;
    uf[i].dad = i;
  }
  ll ans = 0;
  for (int i=0;i<m;i++) {

    if (bus(_ed[i].S.F) != bus(_ed[i].S.S)) {
      unir(_ed[i].S.F, _ed[i].S.S);
      ans += _ed[i].F;

      g[_ed[i].S.F].push_back({_ed[i].S.S, _ed[i].F});
      g[_ed[i].S.S].push_back({_ed[i].S.F, _ed[i].F});
    }
  }
  dfs(1,1,0,0);

  for (int i=0;i<m;i++) {
    cout << ans - maxPath(ed[i].S.F, ed[i].S.S) + ed[i].F << "\n";
  }
  return 0;
}