#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  reverse(s.begin(),s.end());
  for (auto u : s) {
    if (u=='p') cout<<"q";
    else if (u=='q') cout<<"p";
    else cout<<"w";
  }
  cout<<"\n";
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}