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
  string s;
  cin >> s;
  int i=1, j=n;
  vector<int> ans(n);
  for (int ii=n-2;ii>=0;ii--) {
    if (s[ii] == '<') {
      ans[ii+1] = i++;
    } else {
      ans[ii+1] = j--;
    }
  }
  ans[0] = i;
  for (auto u : ans) {
    cout << u << " ";
  }
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
