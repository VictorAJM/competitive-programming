#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

using ll = long long;
using ii = pair<ll,ll>;

const int N = 1e4+5;

ll n,h,k;
ll x[N],y[N],z[N];
ll a,b;
ll ans[N];
bool vs[N];

ll dist(int u, int v) {
  ll _x = abs(x[u] - x[v]);
  ll _y = abs(y[u] - y[v]);
  _x *= _x;
  _y *= _y;
  return _x + _y;
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> h >> k;
  for (int i=0;i<n;i++) cin >> x[i] >> y[i] >> z[i];
  cin >> a >> b;
  for (int i=0;i<=n;i++) vs[i] = ans[i] = 0;

  
  int ini = -1;
  for (int i=0;i<n;i++) if (x[i] == a && y[i] == b) {
    ini = i;
  }

  if (y[ini] == 0) { 
    cout << "0\n";
    return 0;
  }


  queue<ii> q;
  q.push({ini,0});
  vs[ini] = 1;
  ans[ini] = 0;
  ans[n] = -1;

  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    if (z[x.F]==1 && abs(y[x.F]) <= h) {
      cout << x.S+1<<"\n";
      return 0;
    }
    for (int i=0;i<n;i++) if (!vs[i]) {
      if (z[x.F]==1 && dist(x.F,i) <= h*h) {
        q.push({i,x.S+1});
        ans[i] = x.S+1;
        vs[i] = 1;
      } else if (z[i] == 1 &&  dist(x.F,i) <= k*k) {
        q.push({i,x.S+1});
        ans[i] = x.S+1;
        vs[i] = 1;
      }
    }
  }

  cout << ans[n] << "\n";
  return 0;
}