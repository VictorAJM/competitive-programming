#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, q, a[N];

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i=1;i<=n;i++) cin >> a[i];

  map<int,long long> div, next, ans;
  for (int i=1;i<=n;i++) {
    next.clear();
    for (auto d : div) {
      next[__gcd(d.first, a[i])] += d.second;
    }
    next[a[i]]++;

    swap(div, next);
    for (auto u : div) {
      ans[u.first] += u.second;
    }
  }

  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << "\n";
  }
  return 0;
}