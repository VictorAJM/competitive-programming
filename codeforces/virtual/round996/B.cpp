#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int& i:a) cin >> i;
  for(int& i:b) cin >> i;
  int cnt = 0;
  for (int i=0;i<n;i++) if (a[i] < b[i]) cnt++;
  if (cnt>1) {
    cout<<"NO\n";
    return;
  } 
  if (cnt == 0 ) {
    cout<<"YES\n";
    return;
  }
  for (int i=0;i<n;i++) if (a[i] < b[i]) cnt = b[i]-a[i];
  for (int i=0;i<n;i++) if (a[i] >= b[i]) if (a[i]-b[i] < cnt) {
    cout<<"NO\n";
    return;
  } 
  cout<<"YES\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}