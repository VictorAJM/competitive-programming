#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;

void solve() {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k==0) {
    string r = s;
    reverse(r.begin(), r.end());
    if (s >= r) cout<<"NO\n";
    else cout <<"YES\n";
    return;
  }
  string r = s;
  sort(r.begin(), r.end());
  if (r[0] == r[n-1]) {
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}