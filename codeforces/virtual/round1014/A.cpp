#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  sort(a.begin(), a.end());
  cout<<a[n-1]-a[0]<<"\n";
} 
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}