#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define F first
#define S second

using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;
using vii = vector<ii>;

void _swap(int i, int j, vi &a, vi &b, vector<ii> &ans) {
  ans.pb({i+1, j+1});
  swap(a[i], a[j]);
  swap(b[j], b[i]);
}

pair<vector<int>, vector<int>> trans(vi &a, vi &b, vector<ii> &c) {
  set<ii> s;
  map<ii, int> m;
  for (int i=0;i<sz(a);i++) {
    s.insert({a[i], b[i]});
  }
  int q = 0;
  for (auto [u, v] : s) {
    m[{u, v}] = ++q;
  }
  vector<int> ans(sz(a), 0), ans2(sz(a), 0);
  for (int i=0;i<sz(a);i++) {
    ans[i] = m[{a[i], b[i]}];
  }
  for (int i=0;i<sz(c);i++) {
    ans2[i] = m[c[i]];
  }
  return {ans, ans2};
}

vector<ii> find_swaps(vi &a, vi &b) {
  vector<ii> swaps;
  vector<set<int>> m(sz(a)+2);

  for (int i=0;i<sz(a);i++) {
    m[a[i]].insert(i);
  }

  for (int i=0;i<sz(b);i++) {
    m[a[i]].erase(i);
    if (a[i] != b[i]) {
      int x = *m[b[i]].begin();
      swaps.push_back({i, x});
      m[b[i]].erase(x);
      m[a[i]].insert(x);
      swap(a[i], a[x]);
    }
  }

  return swaps;
}

void solve() {
  int n; cin >> n;
  vi a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int I = 0, J = n-1;
  vector<ii> ans;
  map<ii, int> m;
  for (int i=0;i<n;i++) if (a[i]==b[i]) {
    m[{a[i], b[i]}]++;
  }
  int t = 0;
  for (auto [u, v] : m) if (v%2==1) t++;
  if (t != n%2) {
    cout << "-1" << endl;
    return;
  }

  for (int i=0;i<n;i++) {
    if (a[i] == b[i] && m[{a[i], b[i]}]%2==1) {
      if (i!=n/2 && (a[n/2]!=a[i] || b[n/2]!=b[i])) _swap(i, n/2, a, b, ans);
      i = n;
    }
  }

  m.clear();
  for (int i=0;i<n;i++) {
    if (a[i] != b[i]) {
      m[{a[i], b[i]}]++;
    }
  }
  for (auto [u, v] : m) {
    if (m[u] != m[{u.S, u.F}]) {
      cout << "-1" << endl;
      return;
    }
  }
  map<ii,int> m2;
  for (int i=n-1;i>=0;i--) {
    m2[{a[i], b[i]}]++;
  }
  set<ii> s;
  vector<ii> _ans(n);
  for (auto [u, v] : m2) {
    if (s.count({u.S, u.F}) == 1) continue;
    s.insert(u);
    for (int i=(u.F==u.S);i<v;i++) {
      _ans[I] = u;
      _ans[J] = {u.S, u.F};
      I++;
      J--;
      if (u.F == u.S) i++;
    }
  }

  if (n%2==1)  {
    _ans[n/2] = {n+1, n+1};
  }


  vector<int> arr1, arr2;
  auto x = trans(a, b, _ans);
  arr1 = x.F;
  arr2 = x.S;

  auto swaps = find_swaps(arr1, arr2);
  cout << swaps.size() + ans.size() << endl;
  if (ans.size() > 0) {
    for (auto [i, j] : ans) {
      cout << i << " " << j << endl;
    }
  }
  for (auto [i, j] : swaps) {
    cout << i+1 << " " << j+1 << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
