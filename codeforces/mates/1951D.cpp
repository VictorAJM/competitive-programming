#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll n,k;
  cin >> n >> k;
  if (n < k) {
    cout <<"NO\n";
    return;
  }
  if (n==k) {
    cout<<"YES\n1\n1\n";
    return;
  }
  if (n>=k+k-1) {
    cout << "YES\n2\n"<<n-k+1<<" "<<1<<"\n";
    return;
  }  
  cout <<"NO\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}