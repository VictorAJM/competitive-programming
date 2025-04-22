#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int d[100005];
int tam[100005];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i=1;i<=n;i++) {
    int x,v;
    cin >> x;
    for (int j=1;j<=x;j++) {
      cin >> v;
      g[v].push_back(i);
      d[i]++;
    }
  }
  queue<int> q;
  for (int i=1;i<=n;i++) {
    if (d[i] == 0) {
      q.push(i);
      tam[i]=1;
    }
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i=0;i<g[v].size();i++) {
      int u = g[v][i];
      d[u]--;
      tam[u] = max(tam[u], tam[v] + 1);
      if (d[u] == 0) {
        q.push(u);
      }
    }
  }
  for (int i=1;i<=n;i++) {
    if (tam[i]==n) {
      cout << 1 << '\n';
      return 0;
    }
  }
  cout << "0\n";
  return 0;
}