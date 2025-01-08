#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;

void solve() {
  ll n,k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n);
  for(int& i:a) cin >> i;
  for(int& i:b) cin >> i;
  vector<ii> events;
  for (int i=0;i<n;i++) {
    events.push_back({a[i], 0 });
    events.push_back({b[i], 1});
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(events.begin(), events.end());
  ll ans = 0;
  for (auto u : events) {
    auto total = n-(lower_bound(b.begin(),b.end(), u.F) - b.begin());
    auto buenos = n-(lower_bound(a.begin(),a.end(),u.F) - a.begin());
    if (total-buenos > k) continue;
    ll ganancia = u.F*(total);

    ans=max(ganancia, ans);
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}