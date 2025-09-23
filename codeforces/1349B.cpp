#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int& i:a) cin >> i;

  bool flag = 0;
  for (int i : a) if (i == k) flag = 1;
  if (!flag) {
    cout <<"no\n";
    return;
  }
  if (n==1) {
    cout << "yes\n";
    return;
  }

  int prev = -3;
  for (int i=0;i<n;i++) {
    if (a[i] >= k) {
      if (i-prev <= 2) {
        cout<<"yes\n";
        return;
      }
      prev = i;
    } 
  }
  cout << "no\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}