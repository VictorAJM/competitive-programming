#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  n--;
  long long ans = 0;
  long long p=1;
  while (n) {
    ans += p*((n+1)/2);
    n/=2;
    p*=2;
  }
  cout<<ans;
  return 0;
}