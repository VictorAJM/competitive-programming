#include <bits/stdc++.h>
#define F first
#define S second


using namespace std;
const int N = 2e5+5;

using ii = pair<int,int>;

int n, d[N];
bool vs[N];
vector<int> g[N];

int main() {
  int tam = 0;
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i=1;i<n;i++) {
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<ii> q;
  q.push({1,0});
  vs[1] = 1;
  d[1] = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto v : g[u.F]) {
      if (!vs[v]) {
        q.push({v, u.S+1});
        vs[v] = 1;
        d[v] = u.S+1;
      }
    }
  }

  int dis = *max_element(d+1, d+n+1);
  int a;
  for (int i=1;i<=n;i++) if (d[i] == dis) {
    a = i;
    i = n+1;
  }


  for(int i=1;i<=n;i++) vs[i] = d[i] = 0;
  q.push({a,0});
  vs[a] = 1;
  d[a] = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto v : g[u.F]) {
      if (!vs[v]) {
        q.push({v, u.S+1});
        vs[v] = 1;
        d[v] = u.S+1;
      }
    }
  }

  dis = *max_element(d+1, d+n+1);
  int b;
  for (int i=1;i<=n;i++) if (d[i] == dis) {
    b = i;
    i = n+1;
  }

  tam = dis;

  vector<int> cosas_en_medio;
  int c = b;
  cosas_en_medio.push_back(b);
  while (d[c] > 0) {
    for (int i=0;i<(int)g[c].size();i++) if (d[g[c][i]] == d[c]-1) {
      c = g[c][i];
      i = n+1;
    }
    cosas_en_medio.push_back(c);
  }

  for(int i=1;i<=n;i++) vs[i] = d[i] = 0;
  for (auto u : cosas_en_medio) q.push({u,0});
  for (auto u : cosas_en_medio) vs[u] = 1;
  d[a] = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto v : g[u.F]) {
      if (!vs[v]) {
        q.push({v, u.S+1});
        vs[v] = 1;
        d[v] = u.S+1;
      }
    }
  }

  dis = *max_element(d+1, d+n+1);
  int cc;
  for (int i=1;i<=n;i++) if (d[i] == dis && i != a && i != b) {
    cc = i;
    i = n+1;
  }

  tam += dis;
  cout << tam << "\n";
  cout << a << " "<< b << " "<<cc;
  return 0;
}