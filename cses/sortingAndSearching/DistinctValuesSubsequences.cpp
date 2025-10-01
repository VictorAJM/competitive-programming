#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;

  map<int,long long> m;
  for (int i:a) m[i]++;
  long long ans = 1;

  for (auto u : m) {
    ans *= (u.second + 1);
    ans %= 1000000007;
  }
  ans--;

  cout << ans << "\n";

}