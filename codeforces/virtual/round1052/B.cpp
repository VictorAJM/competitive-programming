#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+5;
const int M = 1e5+5;

int n,m,l[N];
vector<int> s[N];
int cnt[M];
bool valid[N];
vector<int> g[M];

void solve() {
  cin >> n >> m;
  
  for (int i=0;i<n;i++) s[i].clear();
  for (int i=1;i<=m;i++) cnt[i] = 0;
  for (int i=1;i<=m;i++) g[i].clear();

  int x;

  for (int i=0;i<n;i++) {
    cin >> l[i];
    for (int j=0;j<l[i];j++) {
      cin >> x;
      s[i].push_back(x);
      cnt[x]++;
      g[x].push_back(i);
    }
  }
  
  for (int i=1;i<=m;i++) if (cnt[i] == 0) {
    cout << "NO\n";
    return;
  }

  for (int i=0;i<n;i++) valid[i] = 1;
  for (int i=0;i<n;i++) for (auto u : s[i]) if (cnt[u] == 1) valid[i] = 0;
  
  int valids = 0;
  for (int i=0;i<n;i++) if (valid[i]) valids++;

  if (valids >= 2) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}