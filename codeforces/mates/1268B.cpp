#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t = 0;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  ll x = 0, y = 0;
  for (int i:a) {
    swap(x,y);
    x += i/2;
    y += (i+1)/2;
  }
  cout << min(x, y) << "\n";
  return 0;
}