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
    map<int,int> m;
    int n;
    cin >> n;
    vector<vi> a(n);
    for (int i=0;i<n;i++) {
      int k;
      cin >> k;
      for (int j=0;j<k;j++) {
        int x;
        cin >> x;
        a[i].push_back(x);
      }
    }
    for (int i=0;i<n;i++) for (auto j : a[i]) m[j]++;
    for (int i=0;i<n;i++) {
      bool t = 1;
      for (auto j : a[i]) if (m[j]==1) t=0;
      if (t) {
        cout<<"Yes\n";
        return;
      }
    }
    cout << "No\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}