#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> a(n);
  for(auto& i:a) cin >> i.S >> i.F;
  sort(a.begin(), a.end());
  multiset<int> s;
  for (int i=0;i<k;i++) s.insert(0);
  int cnt = 0;
  for (auto& i:a) {
    auto p = s.lower_bound(i.S+1);
    if (p!=s.begin()) {
      p--;
      s.erase(p);
      s.insert(i.F);
      cnt++;
    }
  }
  cout << cnt << " ";
  return 0;
}