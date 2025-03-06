#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n,k,p;
  cin >> n >> k >> p;
  if (n*p < abs(k)) cout<<"-1\n";
  else cout << (abs(k)+p-1) / p << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}