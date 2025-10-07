#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
void solve() {
  int n;
  cin >> n;
  vector<ii> a(n);
  for (int i=0;i<n;i++) cin >> a[i].F;
  for (int i=0;i<n;i++) cin >> a[i].S;
  for (int i=0;i<n;i++) if (a[i].F>a[i].S) swap(a[i].F, a[i].S);
  sort(a.begin(), a.end());
  ll s=0;
  for (int i=0;i<n;i++) s+=a[i].S-a[i].F;
  set<ll> st;
  ll ans = 0;
  for (int i=0;i<n;i++) {
    st.insert(a[i].S+a[i].S);
    ans = max(ans, 2*a[i].F - (*st.begin()));
  }
  cout << s+ans << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}