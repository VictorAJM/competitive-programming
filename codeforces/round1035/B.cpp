#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll px,py,qx,qy,n;
  cin >> n;
  cin >> px >> py >> qx >> qy;
  vector<ll> a(n);
  for(auto& i:a) cin >> i;
  for(auto& i:a) i = i*i;
  ll d = (qx-px)*(qx-px) + (qy-py)*(qy-py);
  ll A,B;
  A = B = d;
  for (int i=0;i<n-1;i++) {
    A = A+a[i];
    B = B-a[i];
  }
  if (B <= a[n-1] && a[n-1] <= A) {
    cout << "Yes\n";
    return;
  }
  cout << "No\n";
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}