#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int deg[200005];
bool vs[200005];
int dfs(int no) {
  vs[no] = 1;
  int sum = 0;
  int z = 0;
  for (auto u : g[no]) if (!vs[u]) {
    int res = dfs(u);
    sum += res;
    if (res==0) z++;
  }
  sum += max(0,z-1);
  return sum;
}
void solve() {
  int n;
  cin >> n;
  for (int i=1;i<=n;i++) g[i].clear(), deg[i]=vs[i]=0;
  for (int i=1;i<n;i++) {
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    deg[a]++; deg[b]++;
  }
  if (*max_element(deg+1, deg+n+1)==0) {
    cout<<"0\n";
    return;
  }
  if (*max_element(deg+1, deg+n+1) < 3) {
    cout<<"1\n";
    return;
  }
  for (int i=1;i<=n;i++) if (deg[i]>=3) {
    cout << dfs(i) << "\n";
    return;
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}