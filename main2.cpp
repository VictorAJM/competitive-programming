#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000];

int main() {
  int n,m;
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i=1;i<=n;i++) {
    cout << "Para el nodo "<<i<<" su grado es: "<<g[i].size()<<"\n";
  }
  return 0;
}
