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

void solve() {
  int n;
  cin >> n;
  if (n%2==0) cout<<"-1\n";
  else {
    cout << n << " ";
    for(int i=1; i < n; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
