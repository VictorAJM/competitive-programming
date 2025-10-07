#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(auto& i:a) cin >> i;
  ll s = 0;
  for (auto i:a) s += i;
  if (s%(((n)*(n+1))/2)!=0) {
    cout<<"NO\n";
    return;
  }
  ll p = s/(((n)*(n+1))/2);
  cerr << p << " ";
  cout << "*\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}