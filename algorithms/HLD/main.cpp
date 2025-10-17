#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> class MaxSegmentTree {
  private:
    const T DEFAULT = 0;
    int len;
    vector<T> segtree;

  public:
    MaxSegmentTree(int len): len(len), segtree(len*2, DEFAULT) {}

    void set(int ind, T val) {
      ind += len;
      segtree[ind] = val;
      for (; ind > 1; ind /= 2) {
        segtree[ind/2] = max(segtree[ind], segtree[ind^1]);
      } 
    }

    T range_max(int start, int end) {
      T _max = DEFAULT;
      for (start += len, end += len; start < end; start /=2, end /=2) {
        if (start%2==1) _max = max(_max, segtree[start++]);
        if (end%2==1) _max = max(_max, segtree[--end]);
      }
      return _max;
    }
};


template <class T, bool VALS_IN_EDGES> class HLD {
  private:
    int N, R, tim = 0;
    vector<vector<int>> g;
    vector<int> par, siz, depth, rt, pos;
    MaxSegmentTree<T> segtree;

    void dfs_sz(int v) {
      if (par[v] != -1) g[v].erase(find(g[v].begin(), g[v].end(), par[v]));
      for (int &u : g[v]) {
        par[u] = v;
        depth[u] = depth[v] + 1;
        dfs_sz(u);
        siz[v] += siz[u];
        if (siz[u] > siz[g[u][0]]) swap(u, g[v][0]);
      }
    }

    void dfs_hld(int v) {
      pos[v] = tim++;
      for (int u : g[v]) {
        rt[u] = (u == g[v][0] ? rt[v] : u);
        dfs_hld(u);
      }
    }

    template <class B> void process(int u, int v, B op) {
      for (; rt[u] != rt[v]; v = par[rt[v]]) {
        if (depth[rt[u]] > depth[rt[v]]) swap(u,v);
        op(pos[rt[v]], pos[v]);
      }
      if (depth[u] > depth[v]) swap(u,v);
      op(pos[u] + VALS_IN_EDGES, pos[v]);
    }

  public:
    HLD(vector<vector<int>> _g, int _R): N(_g.size()) , R(_R), par(N, -1), siz(N, 1), depth(N), rt(N),
    pos(N), segtree(N) {
      rt[R] = R;
      dfs_sz(R);
      dfs_hld(R);
    }

    T query_path(int u, int v) {
      T res = 0;
      process(u, v, [&](int l, int r) {
        res = max(res, segtree.range_max(l, r+1));
      });
      return res;
    }

    void modify_node(int u, T val) { segtree.set(pos[u], val); }
};

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);

  int n,q;
  cin >> n >> q;
  vector<int> v(n);
  vector<vector<int>> g(n);
  for (int i=0;i<n;i++) cin >> v[i];

  for (int i=0;i<n-1;i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  HLD<int, 0> H(g, 0);

  for (int i=0;i<n;i++) H.modify_node(i ,v[i]);

  while (q--) {
    int type, s,a,b,x;
    cin >> type;
    if (type == 1) {
      cin >> s >> x;
      --s;
      H.modify_node(s, x);
    } else if (type ==2) {
      cin >> a >> b;
      a--; b--;
      cout << H.query_path(a, b) << " ";
    }
  }

  return 0;
}