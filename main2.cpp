#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int N = 1e6+5;
using ll = long long;
ll fact[N];

ll eleva(ll base, ll exp) {
  if (exp==0) return 1;
  if (exp==1) return base;
  ll aux = eleva(base, exp/2);
  aux *= aux;
  aux %= mod;
  if (exp%2==1) aux*=base;
  aux%=mod;
  return aux;
}

ll inv(ll val) {
  return eleva(val, mod-2);
}

ll coef(int n, int k) {
  ll aux = 1;
  aux = fact[n];
  aux *= inv(fact[k]);
  aux %= mod;
  aux *= inv(fact[n-k]);
  aux %= mod;
  return aux;
}

int main() {
  
  fact[0] = 1;
  for (int i=1;i<N;i++) {
    fact[i] = fact[i-1]*i;
    fact[i] %= mod;
  }

  cout << coef(6,2) << ":)";
  return 0;
}
