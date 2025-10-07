#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  sort(a.begin(),a.end()); 
  for (int i=2;i<n-1;i++) if (a[i]==a[i+1]) {
    cout <<a[0] <<" "<<a[1] << " "<<a[i+1] << " "<<a[i] << "\n";
    return;
  }
  if (a[0] == a[1]) {
    for (int i=2;i<n-1;i++) if (a[i+1]-a[i]<a[0]+a[1]) {
    cout <<a[0] <<" "<<a[1] << " "<<a[i+1] << " "<<a[i] << "\n";
    return;
    }
  }
  if (a[2] == a[1]) {
    for (int i=3;i<n-1;i++) if (a[i+1]-a[i]<a[2]+a[1]) {
      cout <<a[2] <<" "<<a[1] << " "<<a[i+1] << " "<<a[i] << "\n";
      return;
    }
  }
  cout<<"-1\n";
  return;
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}