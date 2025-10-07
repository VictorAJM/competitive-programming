#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  if (n==k) {
    int j =1;
    while (j<n && a[j*2-1]==j) j++;
    cout<<j<<"\n";
    return;
  }
  int j=1;
  while (j<n && a[j]==1) j++;
  if (n-j >= k-1) {
    cout<<"1\n";
    return;
  }
  cout<<"2\n";
}
int main() {
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}