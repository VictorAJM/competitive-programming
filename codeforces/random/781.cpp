#include <bits/stdc++.h>
using namespace std;
const int  N = 2e5+5;
int n,m,k;
int q = 0;
vector<int> g[N];
bool vs[N];
int low[N],high[N];
void dfs(int u) {
  vs[u]=1;
  low[u] = ++q;
  high[u] = q;
  for (int v :g[u]) if (!vs[v]) {
    dfs(v);
    high[u] = max(low[v],high[u]);
  }
}
int main() {
  cin>>n>>m>>k;
  for (int i=1;i<=m;i++) {
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
    
  }
  
}