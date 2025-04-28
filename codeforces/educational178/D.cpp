#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
bool vs[6000005];
vector<int> pr;
void solve() {
  ll s = 0;
  ll s2 = 0;
  int n;
  cin >> n;
  vector<ll> a(n);
  for(ll& i:a) cin >> i;
  sort(a.begin(), a.end());
  reverse(a.begin(),a.end());
  int ans=0;
  for (int i=0;i<n;i++) {
    s += a[i];
    s2 += pr[i];
    if (s >= s2) ans=i;
  }
  cout << n-ans-1 << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  for (int i=2;i<=6000000;i++) if (!vs[i]) {
    pr.push_back(i);
    for (int j=i;j<=6000000;j+=i) vs[j]=1;
  }
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}