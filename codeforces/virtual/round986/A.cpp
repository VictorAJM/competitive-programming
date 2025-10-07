#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n,a,b;
  cin>>n>>a>>b;
  string s;
  int x=0, y=0;
  cin>>s;
  for (int i=0;i<100;i++) for (int j=0;j<n;j++) {
    if (s[j]=='N') y++;
    else if (s[j]=='E') x++;
    else if (s[j]=='S') y--;
    else x--;
    if (x==a && y == b) {
      cout<<"YES\n";
      return;
    }
  }
  cout<<"NO\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}