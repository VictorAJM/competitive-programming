#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,z;
  cin >> n >> z;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  bool ans=0;
  for (int i:a) if (i) ans=1;
  if (!ans) {
    cout << "YES\n";
    return;
  } 
  int x=0;
  for (int i=0;i<n;i++) if (a[i]) x=i;
  int y = n;
  for (int i=0;i<n;i++) if (a[i]) y=min(y,i);
  if (x-y+1 <= z) cout<<"YES\n";
  else cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}