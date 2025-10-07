#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  map<int,int> m;
  for (int i:a) m[i]++;
  vector<int> b(n, 0);
  for (int i=0;i<n;i++) if (m[a[i]]==1) b[i]=1;
  vector<int> c(n, 0);
  c[0] = b[0];
  for (int i=1;i<n;i++) {
    if (b[i]>0) c[i] = c[i-1];
    c[i] += b[i];
  }
  int p = *max_element(c.begin(), c.end());
  if (p==0) {
    cout<<"0\n";
    return;
  }
  for (int i=0;i<n;i++) if (c[i] == p) {
    cout << i+2-c[i] <<" "<<i+1<<"\n";
    return;
  }

}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}