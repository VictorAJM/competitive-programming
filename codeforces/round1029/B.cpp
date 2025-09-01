#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i=1;i<=n;i+=2) cout<<i<<" ";
  if (n%2==1) n--;
  for (int i=n;i>0;i-=2) cout<<i<<" ";
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}