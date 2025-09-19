#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int n,k;
  cin >> n >> k;
  int ans = 0;
  vector<int> l(n), r(n);
  for(int& i : l) cin >> i;
  for (int& i : r) cin >> i;
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  for (int i=0;i<n;i++) {
    if (l[i] + r[i] <= k) {
      ans++;
      k -= l[i] + r[i];
    }
  }
  cout << ans << "\n";
  return 0;
}