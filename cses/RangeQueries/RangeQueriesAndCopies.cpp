/*
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
const int N = 2e5+5;
struct arreglo {
  vector<ll>* v;
  vector<ll>* f;
  int dis=0;
  vector<ii> cambiar;
  void agrega(int pos, ll cuanto) {
    while (pos < (*f).size()) {
      (*f)[pos] += cuanto;
      pos += (pos&(-pos));
    }
  }
  ll obtener(int pos) {
    ll ans = 0;
    while (pos) {
      ans += (*f)[pos];
      pos -= (pos&(-pos));
    }
    return ans;
  }
  ll get(int pos) {
    vector<ii> regreso;
    for (auto u : cambiar) {
      ll diff = u.S - (*v)[u.F];
      (*v)[u.F] += diff;
      regreso.push_back({u.F+1, -diff});
      agrega(u.F+1, diff);
    }
    ll ans = obtener(pos+1);
    for (int i=regreso.size()-1;i>=0;i--) {
      (*v)[regreso[i].F-1] += regreso[i].S;
      agrega(regreso[i].F, regreso[i].S);
    }
    return ans;
  }
  void init() {
    f = new vector<ll>();
    (*f).clear();
    for (int i=0;i<=(*v).size();i++) {
      (*f).push_back(0);
    }
    for (int i=0;i<(*v).size();i++) {
      agrega(i+1, (*v)[i]);
    }
  }
} lista[N];
int lista_cnt,n,q;
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> q;
  int r = 100;
  vector<ll> a(n);
  for (int i=0;i<n;i++) cin >> a[i];
  lista[0].v = new vector<ll>(a);
  lista[0].init();
  lista_cnt = 1;
  for (int i=1;i<=q;i++) {
    int t,k,a,b,x;
    cin >> t >> k; k--;
    if (t==1) {
      cin >> a >> x;
      a--;
      lista[k].cambiar.push_back({a,x});
      lista[k].dis++;
      if (lista[k].dis >= r) {
        lista[k].v = new vector<ll>(*lista[k].v);
        
        lista[k].dis = 0;
        for (auto u : lista[k].cambiar) {
          (*(lista[k].v))[u.F] = u.S;
        }
        lista[k].init();
        lista[k].cambiar.clear();
      }
    } else if (t==2) {
      cin >> a >> b;
      a--; b--;
      if (a==0) cout << lista[k].get(b) << "\n";
      else cout << lista[k].get(b) - lista[k].get(a-1) << "\n";
    } else {
      int num = lista_cnt;
      lista[num] = lista[k];
      lista_cnt++;
    }
  }
  return 0;
}

*/

#include <bits/stdc++.h>
#define nodo first
#define tipo second.first
#define P second.second.first
#define S second.second.second
using namespace std;
const int N = 4e5+5;
using query = pair<int, pair<int,int>>;
using ii = pair<int, query>;
using ll = long long;
int n,q,a[N],dir[N];
ll ans[N];
vector<ii> g[N];
ll f[N];
void agrega(int pos, ll cuanto) {
  while (pos < N) {
    f[pos] += cuanto;
    pos += (pos&(-pos));
  }
  return;
}
ll obtener(int pos) {
  ll ans = 0;
  while (pos) {
    ans += f[pos];
    pos -= (pos&(-pos));
  }
  return ans;
}
void dfs(int cur, int lista) {
  for (auto u : g[cur]) {
    if (u.tipo == 0) {
      dfs(u.nodo, u.P);
    } else if ( u.tipo==1) {
      ll diff = u.S-a[u.P];
      agrega(u.P, diff);
      a[u.P] = u.S;
      dfs(u.nodo, lista);
      agrega(u.P, -diff);
      a[u.P] -= diff;
    } else {
      ll r1 = obtener(u.S);
      ll r2 = obtener(u.P-1);
      ans[-u.tipo] = r1-r2;
      dfs(u.nodo, lista);
    }
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> q;
  vector<int> a(n);
  for (int i=0;i<n;i++) cin >> a[i];
  dir[1] = 0;
  int cnt = 1;
  int listas = 1;
  for (int i=0;i<n;i++) {
    g[dir[listas]].push_back({cnt,{1,{i+1,a[i]}}}), dir[listas] = cnt++;
  }
  int query = -1;
  for (int i=1;i<=q;i++) {
    int t,k;
    cin >> t >> k;
    if (t==1) {
      int a,x;
      cin >> a >> x;
      g[dir[k]].push_back({cnt, {1,{a,x}}}), dir[k] = cnt++;
    } else if (t==2) {
      int a,b;
      cin >> a >> b;
      g[dir[k]].push_back({cnt,{query--,{a,b}}}), dir[k] = cnt++;
    } else {
      g[dir[k]].push_back({cnt, {0,{listas+1,0}}});
      dir[++listas] = cnt++;
    }
  }

  dfs(0, 1);
  query = -query;
  for (int i=1;i<query;i++) cout << ans[i] <<"\n";
  return 0;
}