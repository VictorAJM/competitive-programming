#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  long long ans = 1;
  cin >> n;
  for (long long i=2;i<=n;i++) if (n%i==0) {
    long long p = 1;
    while (n%i==0) {
      n/=i;
      p*=i;
    }
    ans *= p - (p/i);
  }
  cout<<ans<<"\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}