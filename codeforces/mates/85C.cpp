#include <bits/stdc++.h>
using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int P = 19;
const int mod = 1e9+7;
int dp[1000005], aux[1000005];

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int ax = 2;
  int bx = 3;
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int& i:a) cin >> i;
  for (int i=0;i<n;i++) {
    for (int j=0;j<P;j++) {
      int aux = 0;
      while (a[i]%primes[j]==0) {
        aux++;
        a[i] /= primes[j];
      }
      aux %= 2;
      if (aux) b[i] += (1<<j);
    }
  }
  dp[0] = 1;
  for (int i=n-1;i>=0;i--) {
    for (int j=0;j<(1<<P);j++) {
      aux[j] = dp[j] + dp[j^b[i]];
      aux[j] %= mod;
    }
    for (int j=0;j<(1<<P);j++) dp[j] = aux[j];
  }
  cout << dp[0]-1 <<"\n";
}