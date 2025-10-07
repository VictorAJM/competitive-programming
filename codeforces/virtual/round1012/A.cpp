#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
void solve() {
  int x,y,a;
  cin >> x >> y >> a;
  a %= (x+y);
  if (a<x) {
    cout<<"NO\n";
    return;
  }
  a-=x;
  if (a<y) {
    cout<<"YES\n";
    return;
  }
  cout<<"NO\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}