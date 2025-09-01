#include <bits/stdc++.h>
using namespace std;

int coef[5005][5005];
int mod = 1e9+7;

int main() {
  int n = 5000;
  for (int i=0;i<=n;i++) coef[i][0] = 1;
  for (int i=0;i<=n;i++) coef[i][i] = 1;

  for (int i=0;i<=n;i++) {
    for (int j=1;j<i;j++) {
      coef[i][j] = coef[i-1][j] + coef[i-1][j-1];
      coef[i][j] %= mod;
    }
  } 
  cout << coef[6][2];
  cout << ":)";
  return 0;
}