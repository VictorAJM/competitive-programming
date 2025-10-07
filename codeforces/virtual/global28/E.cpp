#include <bits/stdc++.h>
using namespace std;
int F(int u, int v, int n) {
  return ((u+v)%(n+n)/2)+1;
}
void solve() {
  int n,m;
  cin>>n>>m;
  if (m>=n+n) {cout<<"NO\n"; return; }
  cout<<"YES\n";
  for (int i=1;i<=n+n;i++) {
    for (int j=1;j<=m;j++) cout<<F(i,j, n)<<" ";
    cout<<"\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
  return 0;
}