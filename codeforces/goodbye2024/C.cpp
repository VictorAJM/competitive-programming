#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
pair<long long,long long> f(long long n, long long k) {
  if (n<k) return {0, 0};
  if (n%2==0) {
    auto ans = f(n/2 ,k );
    return {2*ans.F+(n/2)*ans.S, 2*ans.S};
  } else {
    auto ans = f(n/2, k);
    return {2*ans.F+(n/2+1)*ans.S + n/2+1, 1+2*ans.S};
  }
}
void solve() {
  long long k,n;
  cin>>n>>k;
  cout << f(n,k).F << "\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}