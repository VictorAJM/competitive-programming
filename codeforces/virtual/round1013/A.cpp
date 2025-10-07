#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a[6];
  a[0]=3;
  a[1]=1;
  a[2]=2;
  a[3]=1;
  a[4]=0;
  a[5]=1;
  int cnt=1;
  int n;
  cin >> n;
  int y=0;
  while (n--) {
    int x;
    y++;
    cin >> x;
    if (x<6 && a[x]==1) {
      cnt++;
    }
    if (x<6) a[x]--;
    if (cnt==6) {
      cout<<y<<"\n";
      while (n--) cin >> x;
      return;
    }

  }
  if (cnt==6) cout<<y<<"\n";
  else cout<<"0\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}