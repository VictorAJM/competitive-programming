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
ll dp[128],aux[128];

int contar(int u) {
  int cnt=0;
  while (u) {
    if (u&1) cnt++;
    u/=2;
  }
  return cnt;
}

void solve() {
  for (int i=0;i<128;i++) dp[i]=aux[i]=0;
  dp[127]=1;
  ll n,k;
  cin >> n >> k;
  vi a(n);
  for(int& i:a) cin >> i;
  for (int j=0;j<n;j++) {
    for (int i=0;i<128;i++) {
      int p = (a[j]&i);
      aux[p]+=dp[i];
      aux[p]%=mod;
    }
    for (int i=0;i<128;i++) dp[i] = aux[i] + dp[i];
    for (int i=0;i<128;i++) dp[i]%=mod,aux[i]=0;
  }
  ll ans = 0;
  for (int i=0;i<64;i++) {
    if (contar(i) == k) ans+=dp[i], ans%=mod;
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