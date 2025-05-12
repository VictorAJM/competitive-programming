#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  set<int> s;
  long long ans =0;
  int j=0;
  for (int i=0;i<n;i++) {
    while (j<n && s.count(a[j])==0) {
      s.insert(a[j]);
      j++;
    }
    ans += j-i;
    s.erase(a[i]);
  }
  cout << ans << "\n";
  return 0;
}