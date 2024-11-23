#include <bits/stdc++.h>
using namespace std;
struct UF {
  int ran,dad,m,M;
};
UF uf[500005];
int bus(int u) {
  if (uf[u].dad != u) uf[u].dad = bus(uf[u].dad);
  return uf[u].dad;
}
void unir(int u, int v) {
  u = bus(u); v = bus(v);
  if (u == v) return;
  if (uf[u].ran < uf[v].ran) {
    uf[v].M = max(uf[v].M, uf[u].M);
    uf[v].m = min(uf[u].m, uf[v].m);
    uf[u].dad = v;
    
  } else if (uf[u].ran < uf[v].ran) {
    uf[u].M = max(uf[v].M, uf[u].M);
    uf[u].m = min(uf[u].m, uf[v].m);
    uf[v].dad = u;
  } else {
    uf[v].M = max(uf[v].M, uf[u].M);
    uf[v].m = min(uf[u].m, uf[v].m);
    uf[u].dad = v;
    uf[v].ran++;
  }
}
void solve() {
  int n;
  cin>>n;
  vector<int> b(n);
  for (int i=0;i<n;i++) {
    cin>>b[i];
    uf[i].m = uf[i].M = b[i];
    uf[i].ran = 0;
    uf[i].dad = i;
  }
  vector<int> reg;
  reg.push_back(0);
  for (int i=1;i<n;i++) {
    while (!reg.empty()) {
      int p = bus(reg.back());
      int q = bus(i);
      if (uf[p].M>uf[q].m) {
        unir(reg.back(),q);
        reg.pop_back();
      } else break;

    }
    reg.push_back(i);
  }
  for (int i=0;i<n;i++) {
    int p = bus(i);
    cout<<uf[p].M << " ";
  } 
  cout<<"\n";
}
int main() {
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}