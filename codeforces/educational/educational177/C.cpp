#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = a; i >= b; --i)
#define FORIT(it, x) for (auto it = x.begin(); it != x.end(); ++it)
#define FORALL(it, x) for (auto it : x)
#define reverse(x) x.rbegin(), x.rend()
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define dbg(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl


using namespace std;
using ll = long long;
using ii = pair<int, int>;
void solve() {
  int n;
  cin >> n;
  vector<int> p(n+1);
  vector<int> d(n+1);
  FOR(i, 1, n+1) {
    cin >> p[i];
  }
  FOR(i, 1, n+1) {
    cin >> d[i];
  }
  int ans = 0;
  FOR(i, 1, n+1) {
    if (p[d[i]]==0){
      cout<<ans<<" ";
    } else {
      int j = d[i];
      while (p[j]!=0) {
        int x = p[j];
        p[j] = 0;
        j = x;
        ans++;
      }
      cout<<ans<<" ";
    }
  }
  cout<<endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}