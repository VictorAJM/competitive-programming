#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  ll p = *max_element(a.begin(), a.end());
  vector<pair<ll, ll>> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = {a[i], i};
  }
  set<int> st;
  sort(b.begin(), b.end(), greater<pair<ll, ll>>());
  for (int i = 0; i < n; i++) {
    if (b[i].first == p) {
      st.insert(b[i].second);
    } else {
      auto k = st.lower_bound(b[i].second);
      if (k == st.end()) {
        k--;
      }
      auto j = st.lower_bound(b[i].second);
      if (j != st.begin()) {
        j--;
      }
      ans += min(abs(b[i].second - *k), abs(b[i].second - *j));
      st.insert(b[i].second);
    }

  }
  cout << ans << '\n';
  return 0;
}