#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;

void solve() {
  ll x,y;
  cin >> x >> y;
  if (x==y) {
    cout<<"-1\n";
    return;
  }
  ll k=0;
  ll q=1;
  while (x%2==y%2) {
    if (x%2>0) {
      x++;
      y++;
      k+=q;
    }
    x/=2;
    y/=2;
    q*=2;
  }
  bool flag=0;
  if (x%2) flag=1;
  else flag = 0;
  while (x>0 && y>0) {
    if (x%2!=y%2) {
      q*=2;
      if (x%2) flag=1;
      else flag = 0;
      x/=2;
      y/=2;
    } else {
      k += q/2;
      x++;
      y++;

      if (flag) y--;
      else x--;
      if (x%2) flag=1;
      else flag = 0;
      x/=2;
      y/=2;
      q*=2;
    }
  }
  cout<<k<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}