#include <bits/stdc++.h>
using namespace std;
void solve() {
  int m,a,b,c,x,y;
  cin>>m>>a>>b>>c;
  x=y=0;
  x += a;
  y += b;
  if (x>m) x=m;
  if (y>m) y=m;
  cout<<min(x+y+c, m+m) << "\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}