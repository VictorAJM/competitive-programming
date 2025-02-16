#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
using ll = long long;
ll dp[N];
int n, a[N], sig[N];
int mul[N];
vector<int> primos;
bool vs[N];
short mu[N] = {0,1};
void mobius(){
	for (int i=1;i<N;i++) if (mu[i]) 
    for(int j=i+i;j<N;j+=i) mu[j]-=mu[i];
}
void suma(ll& a, ll b) {
  a += b;
  a%=mod;
  if (a<0) a+=mod;
  a%=mod;
  return;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) {
    for (long long j=1;j*j<=a[i];j++) if (a[i]%j==0) {
      mul[j]++;
      mul[a[i]/j]++;
      if (a[i]/j == j) mul[j]--;
    }
  }
  dp[0]=1;
  for (int i=1;i<=n;i++) {
    dp[i] = dp[i-1];
    suma(dp[i], dp[i]);
  }
  ll ans = 0;
  mobius();
  for (int i=1;i<=100000;i++) {
    suma(ans, mu[i]*(dp[mul[i]]-1));
  }
  cout<<ans<<"\n";
}