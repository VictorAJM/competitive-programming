#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
void solve() {
  long long n,k;
  long long cnt = 0;
  cin >> n >> k;
  if (n%2==1) {
    long long p ;
    if (k%2==1) p=k;
    else p=k-1;
    cnt ++;
    n-=p;
  }
  long long p = k/2;
  p*=2;
  cnt += (n+p-1)/p;
  cout<<cnt<<"\n";
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}