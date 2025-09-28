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
    int g = m[{u,v}];
    c |= (1<<g);
    cout << c <<" ";
  }
  cout << dp[c] << "\n";
}

bool conectados(pair<int,int> &a, pair<int,int> &b) {
  if (a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second) return true;
  return false;
}

bool check(int mask) {
  vector<pair<int,int>> g;
  for (int i=0;i<n;i++) if ((mask&(1<<i))>0) {
    g.push_back(_m[i]);
  }
  vector<int> degs(g.size(), 0);
  for (int i=0;i<(int)g.size();i++) for (int j=i+1;j<(int)g.size();j++) {
    if (conectados(g[i], g[j])) {
      degs[i]++;
      degs[j]++;
    } 
  }
  int cnt = 0;
  for (int i : degs) if (i%2==1) cnt++;
  if (cnt > 2) return false;
  if (cnt == 1) return false;
  return true;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio();

  int cnt = 1;
  for (int i=1;i<=6;i++) for (int j=i;j<=6;j++) {
    m[{i,j}] = cnt-1;
    _m[cnt-1] = {i,j};
    cnt++;
  }

  n = 21;

  dp[0] = 0;
  for (int i=1;i<(1<<n);i++) {
    long long cur = 0;
    for (int j=0;j<n;j++) if ((i&(1<<j))>0) {
      cur += dp[i-(1<<j)];
    } 
    if (check(i)) cur++;
    dp[i] = cur;
    cout <<dp[i]<<" ";
    if (i>5) return 0;
  }
  cout <<dp[3]<<" ";
  int t;
  cin >> t;
  while (t--) solve();
}