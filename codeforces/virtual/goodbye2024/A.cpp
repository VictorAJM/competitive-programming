#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int& i:a) cin>>i;
  for (int i=0;i<n-1;i++) if (min(a[i],a[i+1]) + min(a[i],a[i+1]) > max(a[i],a[i+1])) {
    cout<<"YES\n";
    return;
  }
  cout<<"NO\n";
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}