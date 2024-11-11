#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;
int mat[3][N];
int fw[3];
int a[3][N+1];
int n;
pair<int,int> ans[N];
int k=0;
void solve() {

  cin>>n;
  for (int i=0;i<3;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
  for (int i=0;i<3;i++) for (int j=1;j<=n;j++) mat[i][a[i][j]] = j; 
  for (int i=0;i<3;i++) for (int j=1;j<=n;j++) a[i][mat[i][j]] = j;
  for (int i=0;i<3;i++) {
    fw[i] = a[i][n];
  }
  for (int j=n-1;j>=1;j--) {
    bool win = 0;
    for (int i=0;i<3;i++) {
      if (fw[i] < a[i][j]) win=1;
    }
    if (win) {
      for (int i=0;i<3;i++) {
        if (fw[i] < a[i][j]) ans[j] = {i, mat[i][fw[i]]};
        fw[i] = min(fw[i], a[i][j]);
      }
    }
    if (j==1) {
      if (win) {
        cout<<"YES\n";
      } else {
        cout<<"NO\n";
        return;
      }
    }
  }
  k=0;
  int u = 1;
  pair<int,int> pp;
    while (u != n) {
    k++;
    pp = ans[u];
    u = pp.second;
  }
  cout<<k<<"\n";
  u=1;
  while (u != n) {
    pp = ans[u];
    char jaja;
    if (pp.first==0) jaja='q';
    else if (pp.first==1) jaja='k';
    else jaja='j';
    cout<<jaja<<" "<<pp.second<<"\n";
    u = pp.second;
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
}