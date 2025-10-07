#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
using ii = pair<int,int>;
using i3 = pair<int, ii>;
int n,m;
vector<int> g[N],h[N];
int val[N];
i3 edges[N];
int d[N];
void solve() {
  cin >> n >> m;
  for (int i=0;i<m;i++) cin >> edges[i].F >> edges[i].S.F >> edges[i].S.S;
  for (int i=0;i<=n;i++) g[i].clear(), val[i] = 0, h[i].clear();
  for (int i=0;i<m;i++) {
    if (edges[i].F==1) g[edges[i].S.F].push_back(edges[i].S.S), val[edges[i].S.F]++;
    if (edges[i].F==1) h[edges[i].S.S].push_back(edges[i].S.F);
  }
  queue<ii> q;
  for (int i=1;i<=n;i++) if (g[i].size()==0) q.push({0, i});
  int cnt = 0;
  while (!q.empty()) {
    cnt++;
    auto x = q.front();
    q.pop();
    d[x.S] = x.F;
    for (int u : h[x.S]) {
      val[u]--;
      if (val[u] == 0) q.push({x.F+1, u});
    }
  }
  if (cnt != n) {
    cout<<"NO\n";
    return;
  }
  cout << "YES\n";
  for (int i=0;i<m;i++) if (edges[i].F == 0) {
    if (d[edges[i].S.F] < d[edges[i].S.S]) swap(edges[i].S.F, edges[i].S.S);
    if (d[edges[i].S.F] != d[edges[i].S.S]) {
      cout << edges[i].S.F << " "<<edges[i].S.S<<"\n";
    } else {
      if (edges[i].S.F > edges[i].S.S) swap(edges[i].S.F, edges[i].S.S);
      cout << edges[i].S.F << " "<<edges[i].S.S<<"\n";
    }
  } else {
    cout << edges[i].S.F << " "<<edges[i].S.S<<"\n";
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}