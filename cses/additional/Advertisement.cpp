#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
const int N = 2e5+5;
struct UnionFind {
  int ran;
  int dad;
  ll tam;
} uf[N];
int bus(int u) {
  if (uf[u].dad != u) uf[u].dad = bus(uf[u].dad);
  return uf[u].dad;
}
void unir(int u, int v) {
  u = bus(u);
  v = bus(v);
  if (u==v) return;
  if (uf[u].ran < uf[v].ran) {
    uf[u].dad = v;
    uf[v].tam += uf[u].tam;
  } else if (uf[v].ran < uf[u].ran) {
    uf[v].dad = u;
    uf[u].tam += uf[v].tam;
  } else {
    uf[u].dad = v;
    uf[v].ran++;
    uf[v].tam += uf[u].tam;
  }
}
int main() {
  ll n;
  cin >> n;
  vector<int> k(n);
  for(int& i:k) cin >> i;
  vector<pair<ll,ll>> a(n);
  for (int i=0;i<n;i++) {
    a[i].F = k[i];
    a[i].S = i;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i=0;i<n;i++) {
    uf[i].ran = 0;
    uf[i].dad = i;
    uf[i].tam = 1;
  }
  ll ans = n;
  for (int i=0;i<n;i++) {
    int p = a[i].S;
    if (p>0 && k[p-1]>=k[p]) unir(p-1, p);
    if (p+1<n && k[p+1]>=k[p]) unir(p, p+1);
    ans = max(ans, a[i].F*uf[bus(p)].tam);
  }
  cout<<ans;
  return 0;
}