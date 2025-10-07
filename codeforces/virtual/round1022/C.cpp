#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
struct UF {
  int ran,dad;
} uf[200005];
int bus(int u) {
  if (uf[u].dad != u) uf[u].dad = bus(ufd[u].dad);
  return uf[u].dad;
}
void unir(int u, int v) {
  u = bus(u);
  v = bus(v);
  if (u==v) return;
  if (uf[u].ran > uf[v].ran) {
    uf[v].dad = u;
  } else if (uf[v].ran > uf[u].ran) {
    uf[u].dad=v;
  } else {
    uf[u].dad = v;
    uf[v].ran++;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  map<int,vector<int>> m;
  for (int i=0;i<n;i++) m[a[i]].push_back(i);
  set<int> s;
  for (int i=0;i<n;i++) {
    uf[i].ran=0;
    uf[i].dad=i;
  }
  for (int i:a) s.insert(-i);
  int cnt=0;
  int ans=0;
  for (auto i:s) {
    i=-i;
    for (auto u : m[i]) {

    }
  }
  cout<<ans<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}