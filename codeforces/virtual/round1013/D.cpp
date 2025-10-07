#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll a, ll b, ll c, ll d) {
  ll z = (b/(d+1))*d + (b%(d+1));
  z*=a;
  return (z>=c);
}
void solve() {
  ll n,m,k;
  cin >> n >> m >> k;
  ll gg = ((n*m-k))/n;
  cout << (m)/(gg+1) << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}