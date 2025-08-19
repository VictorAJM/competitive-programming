#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a,b,x,y;
  cin >> a >> b >> x >> y;
  if (a==b) {
    cout << "0\n";
    return;
  }
  if (a>b) {
    if (a%2==1 && a-1==b) {
      cout << y << "\n";
      return;
    }
    cout << "-1\n";
    return;
  }
  int ans = 0;
  while (a<b) {
    if (a%2==0) ans+=min(x,y);
    else ans+=x;
    a++;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}