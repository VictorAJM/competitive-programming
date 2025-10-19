#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll askNew(int u, int v) {
  cout << "2 "<<u<<" "<<v<<endl;
  ll res;
  cin >> res;
  return res;
}

ll askOri(int u, int v) {
  cout << "1 "<<u<<" "<<v<<endl;
  ll res;
  cin >> res;
  return res;
}

void solve() {
  int n;
  cin >> n;
 
  
  ll total = askNew(1,n);
  ll totalO = askOri(1, n);
  ll k = total - totalO;

  ll l=1, r = n; 
  while (l<r) {
    ll mit =(l+r)/2;
    ll suma = askNew(l,mit);
    ll suma2 = askOri(l,mit);
    if (suma == suma2) {
      l = mit+1;
    } else if (suma -k == suma2) {
      r = mit;
    } else {
      ll dif = suma - suma2;
      cout << "! "<<mit-dif+1<<" "<<mit-dif+k<<endl;
      return;
    }
  }
  cout << "! "<<l<<" "<<l+k-1<<endl;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}