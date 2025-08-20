#include <bits/stdc++.h>
using namespace std;

void fill(int x,int y, int l, int r) {

}

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n,vector<int>(m));
  int x = __gcd(n,k);
  int y = k/x;
  if (y==k) {
    
  } else 
  if (y==1) {
    for (int i=0;i<n;i+=x) {
      for (int j=0;j<m;j++) {
        if (j%2==0) {
          for (int q=0;q<x;q++) for (int w=0;w<1;w++) {
            a[i+q][j+w] = q+w+1;
          }
        } else {
          for (int q=0;q<x;q++) for (int w=0;w<1;w++) {
            a[i+(x)-q-1][j+w] = q+w+1;
          }
        }
      }
    }
  } else {
  for (int i=0;i<n;i+=x) for (int j=0;j<m;j+=y) {
    for (int q=0;q<x;q++) for (int w=0;w<y;w++) {
      a[i+q][j+w] = q*y+w+1;
    }
  }
}
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) cout << a[i][j]<<" ";
    cout << "\n";
  }
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}