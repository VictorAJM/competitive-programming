#include <bits/stdc++.h>
using namespace std;
int get(long long l, long long n, vector<int>& a, bool first_n) {
  if (l>n) {
    bool t = 0;
    if (l/2 <= n) {
      for (int i=1;i<=l/2;i++) t^=a[i];
      return t;
    }
    long long p = l/2;
    if (p%2==0) t ^= get(p, n, a, first_n);
    t ^= first_n;
    return t;
  } else return a[l];
}
void solve() {
  long long n,l,r;
  cin >> n >> l >> r;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++) cin >> a[i];
  if (n%2==0) {
    bool gg = 0;
    for (int i=1;i<=(n+1)/2;i++) gg^=a[i];
    a.push_back(gg);
    n++;
  }
  bool t = 0;
  for (int i=1;i<=n;i++) t ^= a[i];
  cout << get(l, n, a, t) << "\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}