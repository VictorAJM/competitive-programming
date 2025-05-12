#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n,a,b;
  cin >> n >> a >> b;
  if (a==b && b==0) {
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout << i << " ";
    cout << "\n";
    for (int i=1;i<=n;i++) cout << i << " ";
    cout<<"\n";
    return;
  }
  if (a+b <= n && a>0 && b>0) cout <<"YES\n";
  else {
    cout << "NO\n";
    return;
  }
    vector<int> p(n), q(n);
    for (int i=1;i<=a+b;i++) p[i-1]=i;
    for (int i=a+b+1;i<=n;i++) p[i-1]=q[i-1]=i;
    for (int i=b;i>=1;i--) q[i-1] = a+i;
    for (int i=b+1;i<=a+b;i++) q[i-1]=i-b;
    for (int i=1;i<=n;i++) cout << p[i-1] << " ";
    cout << "\n";
    for (int i=1;i<=n;i++) cout << q[i-1] << " ";
    cout<<"\n";
    return;
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}