#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n==1) {
    cout<<"NO\n";
    return;
  }
  if (n==2 && s[0]==s[1]) {
    cout<<"NO\n";
    return;
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}