#include <bits/stdc++.h>

using namespace std;

bool check(int n,int u, int p) {
  if (p<0) return false;
  if (p==0 && u==0 && n==0) return true;
  if (u==0) return false;
  int g = u*(u-1);
  g /= 2;
  bool sePuede = false;
  for (int i=0;i<=n/u;i++) {
    sePuede |= check(n-i*u,u-1, p-i*g);
  }
  return sePuede;
}

vector<int> tamanos(int n, int u, int p) {
  int g = u*(u-1);
  g /= 2;
  vector<int> aux;
  if (p==0 &&  u==0 && n==0) {
    return aux;

  }
  for (int i=0;i<=n/u;i++) if (check(n-i*u,u-1,p-i*g)) {

    aux = tamanos(n-i*u,u-1,p-i*g);

    for (int j=0;j<i;j++) {
      aux.push_back(u);

    }

    return aux;
  } 
  return aux;
}

void solve() {
  int n,k;
  cin >> n >> k;

  int tot = n*(n-1); tot/=2;
  tot = tot-k;
  if (!check(n,n,tot)) {
    cout << "0\n";
    return;
  }
  vector<int> tams = tamanos(n,n, tot);
  int cur = n;
  for (auto u : tams) {
    for (int i=cur-u+1;i<=cur;i++) cout << i << " ";
    cur -= u;
  }
  cout << "\n";
  return;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}