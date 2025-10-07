#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  int x=0;
  int y=0;
  for (int i=0;i<n;i++) {
    if (i%2==0 && a[i]=='0') x++;
    else if (i%2==1 && a[i]=='0') y++; 
  }
  for (int i=0;i<n;i++) {
    if (i%2==0 && b[i]=='0') y++;
    else if (i%2==1 && b[i]=='0') x++; 
  }
  if (x>=(n+1)/2 && y>=n/2) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}