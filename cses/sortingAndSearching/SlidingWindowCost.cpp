#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  multiset<long long> left, right;

  long long sumLeft = 0, sumRight = 0, x = 0;
  for (int i=0;i<n;i++) {
    if (i>=k) {
      x = a[i-k];
      if (left.count(x)) {
        left.erase(left.find(x));
        sumLeft -= x;
      } else {
        right.erase(right.find(x));
        sumRight -= x;
      } 
    }

    if (left.size() <= right.size()) {
      left.insert(a[i]);
      sumLeft += a[i];
    } else {
      right.insert(a[i]);
      sumRight += a[i];
    }
    if (left.size() > 0 && right.size()>0) {
      auto max_lwr = left.rbegin();
      auto min_upr = right.begin();
      if (*max_lwr > *min_upr) {
        long long x = *max_lwr;
        long long y = *min_upr;
        left.erase(left.find(x));
        right.erase(right.find(y));
        left.insert(y);
        right.insert(x);
        sumLeft += y - x;
        sumRight += x - y;
      }
    }
    if (i>=k-1) {
      long long median = *left.rbegin();
      cout << median * (left.size()) - sumLeft + sumRight - median * (right.size()) << ' ';
    }
  }
  return 0;
}