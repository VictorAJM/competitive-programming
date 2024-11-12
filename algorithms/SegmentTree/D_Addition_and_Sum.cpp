#include <bits/stdc++.h>
using namespace std;

struct STLP {
  using T = long long;
  int tam;
  vector<T> st;
  vector<T> lp;
  T ans = 0;
  #define lc ((node << 1) + 1)
  #define rc ((node << 1) + 2)

  T oper(T &elem1, T &elem2) {
    return elem1 + elem2;
  }

  void __lazy(int node, T l, T r) {
    st[node] = st[node] + lp[node] * (r - l + 1);
  }

  void __lazyPush(int node, T l, T r) {
    if (l!=r) {
      lp[rc] += lp[node];
      lp[lc] += lp[node];
    }
    lp[node] = 0;
  }

  void __push(int node, T l, T r) {
    if (lp[node] == 0) return;
    __lazy(node, l , r);
    __lazyPush(node, l , r);
  }

  void __pull(int node) {
    st[node] = oper(st[lc], st[rc]);
    return;
  }
  
  void __init(int node, int l, int r, vector<T> &array) {
    if (l==r) {
      st[node] = array[l];
      return;
    }
    int m = (l+r)/2;
    __init(lc, l, m, array);
    __init(rc, m+1, r, array);
    __pull(node);
    return;
  }
  
  void init(int _tam) {
    tam = _tam;
    st.resize(4*tam);
    lp.resize(4*tam);
  }

  void init(vector<T> array) {
    tam = array.size();
    st.resize(4*tam);
    lp.resize(4*tam);
    __init(0,0,tam-1, array);
  }

  void __update(int node, int in, int fi, int l, int r, int v) {
    __push(node, in, fi);
    if (r < in || l>fi) return;
    if (l <= in && fi <= r) {
      lp[node] = v;
      __push(node, in, fi);
      return;
    }
    int mid = (in+fi)/2;
    __update(lc, in, mid,l,r,v);
    __update(rc,mid+1,fi,l,r,v);
    __pull(node);
  }

  void update(int l, int r, int v) {
    __update(0, 0, tam - 1, l, r, v);
  }

  void __query(int node, int in, int fi, int l, int r) {
    __push(node, in, fi);
    if (l>fi || r < in) return;
    if (l <= in && fi <= r) {
      ans = oper(ans, st[node]);
      return;
    }
    int mid = (in+fi)/2;
    __query(lc, in, mid,l,r);
    __query(rc,mid+1,fi,l,r);
  }

  T query(int l, int r) {
    __resetAns();
    __query(0,0,tam-1, l,r);
    return ans;
  }


} stlp;

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  stlp.init(n);
  for (int i=0;i<m;i++) {
    int t;
    cin>>t;
    if (t == 1) {
      int l,r,v;
      cin>>l>>r>>v;
      stlp.update(l, r-1, v);
    } else {
      int l,r;
      cin>>l>>r;
      long long ans = stlp.query(l, r-1);
      cout << ans << "\n";
    }
  }
  return 0;
}