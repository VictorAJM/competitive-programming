#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  map<string,int> mp;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    mp[s]++;
  }
  int ans = 0;
  string _ans;
  for (auto [x, y] : mp) {
    if (y > ans) {
      ans = y;
      _ans = x;
    }
  }
  cout << _ans << '\n';
}