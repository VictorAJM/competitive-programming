#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
bool hasSeven(long long n) {
  while (n) {
    if (n%10==7) return true;
    n/=10;
  }
  return false;
}
void solve() {
  long long n;
  cin >> n;
  int ans = 10;
  for (int i=10;i<=1000000000;i*=10) {
    long long m = n;
    int cnt = 0;
    while (!hasSeven(m)) m += i-1, cnt++;
    ans = min(cnt ,ans);
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}