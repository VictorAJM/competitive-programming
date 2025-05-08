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
  using vi = vector<ll>;

  void solve() {
    ll n;
    cin >> n;
    vi a(n);
    for(ll& i:a) cin >> i;
    sort(all(a));
    ll g=0;
    for (ll i=1;i<n;i++) g = __gcd(g,a[i]-a[i-1]);
    if (g==0) g=1;
    set<ll> s;
    for (ll i:a) s.insert(i);
    ll p = a[n-1];
    while (s.count(p)) p -= g;
    ll ans = 0;
    for (ll i=0;i<n;i++) {
      ans += (a[n-1]-a[i])/g;
    }
    ans += (a[n-1]-p)/g;
    cout << ans << "\n";
  }

  int main() {
    cin.tie(0)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
  }