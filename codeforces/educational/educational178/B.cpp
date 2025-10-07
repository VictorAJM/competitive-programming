#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  multiset<ll> st;
  for(ll& i:a) cin >> i;
  for (ll i:a) st.insert(i);
  ll s = 0;
  for (int i=1;i<=n;i++) {
    cout << *st.rbegin() + s << " ";
    s += a[n-i];
    st.erase(st.find(a[n-i]));
  }
  cout << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}