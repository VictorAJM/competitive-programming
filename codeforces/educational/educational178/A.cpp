#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
void solve() {
  int a,b,c;
  cin >> a >> b >> c;
  int s = a+b+c;
  if (s%3>0) {
    cout<<"NO\n";
    return;
  }
  if (s/3 < b || s/3 < a) {
    cout<<"NO\n";
    return;
  }
  cout << "YES\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}