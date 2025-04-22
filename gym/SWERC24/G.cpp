#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long l = 0, r = 0, n;
  long long R;
  cin >> R;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i];
    l = max(l, ans);
    r = min(r, ans);
  }
  if (l+abs(r) < R) cout<<"uncertain\n";
  else {
    ans = 1;
    for (int i = 0; i < n; i++) {
      ans += a[i];
      ans = max(ans, 0LL);
      ans = min(ans, R);
    }
    cout << ans << '\n';
  }
}