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
  int s = 15;
  FOR(i,4) {
    int x;
    cin >> x;
    s -= x;
  }
  cout << s << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  solve();
  return 0;
}