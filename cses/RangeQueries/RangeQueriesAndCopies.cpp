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