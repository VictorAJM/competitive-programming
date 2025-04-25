#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
int v[1005], h[1005];
int main() {
  int n,m;
  cin >> n >> m;
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      v[i] += (a[i][j]=='*');
      h[j] += (a[i][j]=='*');
    }
  }
  long long ans = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (a[i][j]=='*') ans += (v[i]-1)*(h[j]-1);
    }
  }
  cout << ans;
}