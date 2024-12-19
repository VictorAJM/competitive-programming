#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n,k;
  cin>>n>>k;
  int l=1,r=n;
  int in = 1;
  for (int i=k;i<=n;i+=k) {
    while (in < i ) {
      cout<<r<<" ";
      r--;
      in++;
    }
    in++;
    cout << l << " ";
    l++;
  }
  while (r>=l) cout<<r--<<" ";
  cout<<"\n";
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