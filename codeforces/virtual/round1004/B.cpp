#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i:a) cin >> i;
  vector<int> b(n+2);
  for (int i:a) b[i]++;
  for (int i=1;i<=n;i++) {
    if (b[i]==1) {
      cout<<"No\n";
      return;
    } else {
      if (b[i]>1) {
        b[i] -= 2;
        b[i+1] += b[i];
      }
    }
  }
  cout<<"Yes\n";
  return;
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}