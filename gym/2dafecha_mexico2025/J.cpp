#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long c[1000005];

long long eleva(long long val, long long exp) {
  if (exp==0) return 1;
  if (exp==1) return val;
  long long z = eleva(val, exp/2);
  z*= z;
  z %= mod;
  if (exp%2==1) z*=val;
  z%=mod;
  return z;
}

long long inv(long long val) {
  return eleva(val, mod-2);
}

long long coef(int n, int k) {
  long long ans = c[n];
  ans *= inv(c[k]);
  ans%=mod;
  ans *= inv(c[n-k]);
  ans %= mod;
  return ans;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  c[0] = 1;
  for (long long i=1;i<=1000001;i++) {
    c[i] = i*c[i-1]; c[i] %= mod;
  }

  int t;
  cin >> t;
  while (t--) {
    int n,k;
    cin >> n >> k;
    cout << coef(n+1,k+1) << "\n";
  }

  return 0;
}