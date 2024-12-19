#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for(int& i:a) cin>>i;

  for(int& i:b) cin>>i;
  int p = *max_element(a.begin(),a.end());
  for(int& i:b) if (i<=a[0] || i>p) i=p+1;
  sort(a.begin(),a.end());
  for (int& i:b) {
    int lw = lower_bound(a.begin(),a.end(),i) - a.begin();
    i = n-lw;
  }
  sort(b.begin(),b.end());
  for (int k=1;k<=m;k++) {
    long long sum = 0;
    for (int j=k;j<=m;j+=k) sum+=b[j-1]+1;
    cout<<sum<<" ";
  }
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