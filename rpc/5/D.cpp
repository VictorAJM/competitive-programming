#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

void solve() {
  string a,b;
  getline(cin, a);
  getline(cin, b);
  set<char> s;
  for(auto u : b) s.insert(u);
  string c;
  for (auto u : a) if (s.count(u)==0) c.push_back(u);
  char ant=0;
  string d;
  for (auto u : c) {
    if (ant != u) {
      d.push_back(u);
      ant=u;
    }
  }
  int l = 0, r = d.size() - 1;
  while (l <= r && d[l] == ' ') l++;
  while (r >= l && d[r] == ' ') r--;
  for (int i = l; i <= r; ++i) cout << d[i];
  cout << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t=1;
  //cin >> t;
  while (t--) solve();
  return 0;
}