#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  long long ans = 0;
  priority_queue<int,vector<int>,greater<int>> pq;
  for (int i=0;i<n;i++) {
    pq.push(a[i]);
    if (pq.top()<a[i]) {
      ans += a[i] - pq.top();
      pq.pop();
      pq.push(a[i]);
    }
  }
  cout << ans;
  return 0;
}