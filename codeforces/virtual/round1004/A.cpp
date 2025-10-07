#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

void solve() {
  int x,y;
  cin >> x >> y;
  if (x-y >= 0 && abs(y-x-1)%9==0 ) cout<<"Yes\n";
  else if (y==x+1) cout<<"Yes\n";
  else cout << "No\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}