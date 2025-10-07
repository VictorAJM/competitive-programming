#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
void solve() {
  int n,m;
  cin >> n >> m;
  vector<ii> a(n);
  vector<int> b(n);
  for (int i=0;i<n;i++) cin >> a[i].F, a[i].S = i;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int x = n/2;
  int y = n/2;
  vector<int> todelete;
  set<int> used;
  set<int> availToChange;
  for (int i=1;i<=min(m,4*n);i++) availToChange.insert(i);
  for (int i=0;i<n;i++) {
    if (a[i].F%2==0) {
      if (x>0) {
        if (used.count(a[i].F)==0) {
          x--;
          used.insert(a[i].F);
          b[a[i].S] = a[i].F;
          if (availToChange.count(a[i].F)) availToChange.erase(a[i].F);
        } else {
          todelete.push_back(a[i].S);
        }
      } else {
        todelete.push_back(a[i].S);
      }
    } else {
      if (y>0) {
        if (used.count(a[i].F)==0) {
          y--;
          used.insert(a[i].F);
          b[a[i].S] = a[i].F;
          if (availToChange.count(a[i].F)) availToChange.erase(a[i].F);             
        } else {
          todelete.push_back(a[i].S);
        }
      } else {
        todelete.push_back(a[i].S);
      }
    }
  }
  int _x = 0;
  int _y = 0;
  for (int i : availToChange) {
    if (i%2==0) _x++;
    if (i%2==1) _y++;
  }
  if (_x < x || _y < y) {
    cout<<"-1\n";
    return;
  }
  cout<<x+y<<"\n";
  int j= 0;
  for (int i : availToChange) {
    if (i%2==0) {
      if (x>0) {
        b[todelete[j]] = i;
        j++;
        x--; 
      }
    }
    if (i%2==1) {
      if (y>0) {
        b[todelete[j]] = i;
        j++;
        y--;
      }
    }
  }
  for (int u : b) cout << u << " ";
}
int main() {
  cin.tie(0) -> ios_base::sync_with_stdio(0);
  int t;
  // cin >> t;
  t = 1;
  while (t--) solve();
  return 0;
}