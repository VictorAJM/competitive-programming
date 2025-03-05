#include <bits/stdc++.h>
#define ve vector
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;

void solve() {
  ll n,x,k;
  cin >> n >> x >> k;
  string s;
  cin >> s;
  ll cnt=0;
  int i;  
  for (i=0;i<n&&k>0;i++) {
    if (s[i]=='L') x--;
    else x++;
    k--;
    if (x==0) {
      i=n+1;
      cnt++;
    }
  }
  
  ll tamCiclo=0;

  int j;
  x=0;
  for (j=0;j<n;j++) {
    if (s[j]=='L') x--;
    else x++;
    tamCiclo++;
    if (x==0) {
      j=n+1;
    }
  }
  if (j!=n+2) tamCiclo = k+1;
  if (i!=n+2) tamCiclo = k+1;
  cnt += k/tamCiclo;
  cout<<cnt<<endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}