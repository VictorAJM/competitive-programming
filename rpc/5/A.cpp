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
  int n;
  cin >> n;
  vector<ll> a(n);
  for(ll& i:a) cin >> i;
  priority_queue<ll,vector<ll>,greater<ll>> pq;
  for (ll i:a) pq.push(i);
  ll ans = 0;
  while (pq.size()>=2) {
    auto a = pq.top();
    pq.pop();
    auto b = pq.top();
    pq.pop();
    ans += a+b;
    pq.push(a+b);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}