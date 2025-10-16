#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<int,int>, int> m;
map<int, pair<int,int>> _m;
long long dp[4000005];

void solve() {
  int n;
  cin >> n;
  long long c = 0;
  for (int i=0;i<n;i++) {
    int u,v;
    cin >> u >> v;
    int g = (u-1)*6 + v-1;
    c |= (1<<g);
  }
  cout << dp[c] << "\n";
}

bool conectados(pair<int,int> &a, pair<int,int> &b) {
  if (a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second) return true;
  return false;
}

vector<int> G[23];
int tam = 0;
void dfs(int no, vector<int>& vs) {
  vs[no] = 1;
  tam++;
  for (auto u : G[no]) if (!vs[u]) dfs(u,vs);
}

bool check(int mask) {
  vector<pair<int,int>> g;
  for (int i=0;i<n;i++) if ((mask&(1<<i))>0) {
    int p = i/6+1;
    int q = i%6+1;
    g.push_back({p,q});
  }
  vector<int> degs(g.size(), 0);
  for (int i=0;i<(int)g.size();i++) {
    G[i].clear();
  }
  return true;
  for (int i=0;i<(int)g.size();i++) for (int j=i+1;j<(int)g.size();j++) {
    if (conectados(g[i], g[j])) {
      degs[i]++;
      degs[j]++;
      G[i].push_back(j);
      G[j].push_back(i);
    } 
  }

  vector<int> vs((int)g.size(), 0);
  tam = 0;
  dfs(0, vs);
  if (tam != g.size()) return false;

  int cnt = 0;
  for (int i : degs) if (i%2==1) cnt++;
  if (cnt > 2) return false;
  if (cnt == 1) return false;
  return true;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio();


  n = 21;

  dp[0] = 0;
for(int i = 1; i<(1<<n); ++i)
	    dp[i] = check(i);
    for(int i = 0;i < n; ++i) for(int mask = 0; mask < (1<<n); ++mask){
        if(mask & (1<<i))
            dp[mask] += dp[mask^(1<<i)];
  }
  int t;
  cin >> t;
  while (t--) solve();
}