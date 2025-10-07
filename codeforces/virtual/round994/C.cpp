#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n,x,y;
  cin>>n>>x>>y;
  vector<int> a(n+1, -1);
  a[x]=0;
  a[y]=1;
  int p = x+1;
  int z = y-x-1;
  int yy = y-x-1;
  while (p<y) {
    if (z>0 && z%2==1) a[p] = 2;
    z=0;
    if (a[p]==-1) {
      if (yy%2==0) a[p]=1;
      else a[p]=0;
    }
    yy--;
    p++;
  }
  p = x-1;
  if (p==0) p=n;
  z = n-(y-x+1);
  yy = n-(y-x+1);
  while (p!=y) {
    if (z>0 && z%2==1) a[p] = 2;
    z=0;
    if (a[p]==-1) {
      if (yy%2==0) a[p]=1;
      else a[p]=0;
    }
    yy--;
    p--;
    if (p==0) p=n;
  }
  for (int i=1;i<=n;i++) cout<<a[i]<<" ";
  cout<<"\n";
}
int main() {
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}