#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> a(m);
  for(int& i:a) cin >> i;
  if (a[0]+m-1 == a[m-1]) {
    cout << n-a[m-1]+1 << "\n";
    return;
  }
  cout << "1\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}