#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin>>n;
  vector<int> a(n);
  for (int& i:a) cin>>i;
  for (int i=1;i<=n;i++) {
    if (a[i-1]==i) {
      // ok
    } else {
      if (i<n && a[i]==i && a[i-1]==i+1) {
        // ok
        swap(a[i],a[i-1]);
      } else {
        cout<<"NO\n";
        return;
      }
    }
  }
  cout<<"YES\n";
}
int main() {
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}