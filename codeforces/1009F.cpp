#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[1000005];
vector<int> l[1000005];
int ans[1000005];
int peso[1000005];
int idx[1000005];
bool vs[1000005];
void dfs(int u) {
  vs[u] = 1;
  vector<int> s;
  for (auto v : g[u]) if (!vs[v]) dfs(v), s.push_back(v);
  if (s.empty()) {

    l[idx[u]].push_back(1);
    ans[u] = 0;
    peso[u] = 1;


    return;
  }
  sort(s.begin(),s.end(),[&](int u, int v){
    if (l[idx[u]].size()>l[idx[v]].size()) return true;
    return false;
  });

  idx[u] = idx[s[0]];
  l[idx[u]].push_back(1); // l[idx[u]].push_back(u);
  if (ans[s[0]]>0) ans[u] = ans[s[0]]+1,peso[u] = peso[s[0]];
  else ans[u] = 0, peso[u] = 1;
  for (int i=1;i<s.size();i++) {
    int r;
    for (int j=l[idx[s[i]]].size()-1, r=l[idx[u]].size()-2;j>=0;j--) {
      l[idx[u]][r]+=l[idx[s[i]]][j];
      if (l[idx[u]][r] > peso[u] || (l[idx[u]][r] == peso[u] && ans[u]>l[idx[u]].size()-1-r)) {
        ans[u] = l[idx[u]].size()-1-r;
        peso[u] = l[idx[u]][r];
      }
      r--;
      
    }
  }

}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i=1;i<=n;i++) idx[i] = i;
  for (int i=1;i<n;i++) {
    int u,v; 
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  for (int i=1;i<=n;i++) cout<<ans[i]<<"\n";
  return 0;
}