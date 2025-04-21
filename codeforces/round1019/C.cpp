#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define F first
#define S second

using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;
using vii = vector<ii>;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) a[i] = (a[i]>k);
  int x=0;
  int y=0;
  int _=0;
  for (int i=0;i<n;i++) {
    if (x<y || x==0) {
      if (a[i]==1) y++;
      else x++;
      _++;
    }
    if (x>=y && x>0) break;
  }
  x=y=0;
  int __=n-1;
  for (int i=n-1;i>=0;i--) {
    if (x<y || x==0) {
      if (a[i]==0) x++;
      else y++;
      __--;
    }
    if (x>=y && x>0) break;
  }
  if (_ <= __) {
    cout << "YES" << endl;
    return;
  }



  x=y=_=0;
  for (int i=0;i<n;i++) {
    if (x>0 && x>y && a[i]==1) {
      y++;
      _++;
      break;
    }  else {
      if (x<y || x==0) {
        if (a[i]==1) y++;
        else x++;
        _++;
      } else {
        if (x>=y && x>0) break;
      }
    }
    
  }
  x=y=0;
  for (int i=_;i<n;i++) {
    if (x<y || x==0) {
      if (a[i]==0) x++;
      else y++;
      _++;
    }
    if (x>=y && x>0 && i+1<n) {
      cout << "YES" << endl;
      return;
    }
  }



  x=y=0;
  __ = n-1;
  for (int i=n-1;i>=0;i--) {
    if (x>0 && x>y && a[i]==1) {
      y++;
      __--;
      break;
    }  else {
      if (x<y || x==0) {
        if (a[i]==1) y++;
        else x++;
        __--;
      } else {
        if (x>=y && x>0) break;
      }
    }
  }
  x=y=0;
  for (int i=__;i>=0;i--) {
    if (x<y || x==0) {
      if (a[i]==0) x++;
      else y++;
      _++;
    }
    if (x>=y && x>0 && i>0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout<<"NO"<<endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
