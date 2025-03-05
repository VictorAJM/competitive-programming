#include <bits/stdc++.h>
#define ve vector
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using i3 = pair<int, ii>;
const int mod = 998244353;
ll level[300005];
ve<int> g[300005];
void solve() {
  int n;
  ll ANS=0;
  cin >> n;
  ve<int> p(n+1);
  ve<ll> ans(n+1);
  for (int i=0;i<=n;i++) g[i].clear();
  for (int i=2;i<=n;i++) cin >> p[i], g[p[i]].push_back(i);
  queue<i3> q;
  for (int i=0;i<=n;i++) level[i] = 0;
  level[0] = 1;
  ans[1] = 1;
  for (int u : g[1]) level[1]++, ans[u] = 1;
  for (int u : g[1]) for (int v : g[u]) q.push({2, {u, v}});
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    ans[p.S.S] = level[p.F-1]-ans[p.S.F];
    if (ans[p.S.S]<0) ans[p.S.S] += mod;
    ans[p.S.S] %=mod;

    level[p.F] += ans[p.S.S];
    if (level[p.F]<0) level[p.F]+=mod;
    level[p.F] %= mod;
    
    for (auto u : g[p.S.S]) q.push({p.F+1, {p.S.S, u}});
  }
  for (int i=1;i<=n;i++) ANS += ans[i], ANS%=mod;
  cout<<ANS<<"\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}