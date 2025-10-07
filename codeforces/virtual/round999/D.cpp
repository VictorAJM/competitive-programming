#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const int mod = 998244353;
const int N = 500;

void solve() {
  int n,m;
  cin >> n >> m;
  multiset<int> s,d;
  priority_queue<int> q;
  for (int i=0;i<n;i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  for (int i=0;i<m;i++) {
    int x;
    cin >> x;
    if (s.count(x) > 0) {
      s.erase(s.find(x));
    } else {
      d.insert(x);
    }
  }
  ll sum = 0;

  for (auto u : s) sum += u;
  for (auto u : d) sum -= u;
  if (sum!=0) {
    cout<<"No\n";
    return;
  }
          set<ll> pro;
          map<ll,ll> a,b;
          for (auto u : s) b[u]++,q.push(u),pro.insert(u);
  for (auto u : d) q.push(u),pro.insert(u),a[u]++;

  while (!q.empty()) {
    auto i = q.top();
    q.pop();
    if (b[i] <= 0) a[i] += -b[i];
    else {
      cout<<"No\n";
      return;
    }
    int x = i/2;
    int y = i/2;
    if (i%2==1) y++;
    b[x] -= a[i];
    if (b[x] < 0 ) {   a[x] += -b[x], b[x] = 0;  }
    if (pro.count(x)==0) {q.push(x); pro.insert(x);}
    b[y] -= a[i];
     if (pro.count(y)==0) {q.push(y); pro.insert(y);} 
    if (b[y] < 0 ) { a[y] += -b[y], b[y] = 0; }
  }
  cout<<"Yes\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}