#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using i3 = pair<int,ii>;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  queue<i3> q;
  q.push({2,{1,1}});
  priority_queue<i3,vector<i3>,greater<i3> > w;

  for (int i=0;i<n;i++) {
    if (a[i]==0) {
      auto x = q.front();
      q.pop();
      cout << x.S.F << " "<<x.S.S<<"\n";
      w.push({x.F+1,{x.S.F+1, x.S.S}});
      w.push({x.F+1,{x.S.F, x.S.S+1}});
      w.push({x.F+4,{x.S.F+1, x.S.S+1}});
      if (x.S.S==1) {
        q.push({x.F+3, {1, x.F+2}});
      } else {
        q.push({x.F, {x.S.F+3, x.S.S-3}});
      }
    } else {
      if (w.empty()) {
        auto x = q.front();
        q.pop();
        cout << x.S.F << " "<<x.S.S<<"\n";
        w.push({x.F+1,{x.S.F+1, x.S.S}});
        w.push({x.F+1,{x.S.F, x.S.S+1}});
        w.push({x.F+4,{x.S.F+1, x.S.S+1}});
        if (x.S.S==1) {
          q.push({x.F+3, {1, x.F+2}});
        } else {
          q.push({x.F, {x.S.F+3, x.S.S-3}});
        }
      } else {
        auto x = q.front();
        auto y = w.top();
        if (x<y) {
          q.pop();
          cout << x.S.F << " "<<x.S.S<<"\n";
          w.push({x.F+1,{x.S.F+1, x.S.S}});
          w.push({x.F+1,{x.S.F, x.S.S+1}});
          w.push({x.F+4,{x.S.F+1, x.S.S+1}});
          if (x.S.S==1) {
            q.push({x.F+3, {1, x.F+2}});
          } else {
            q.push({x.F, {x.S.F+3, x.S.S-3}});
          }
        } else {
          w.pop();
          cout << y.S.F << " "<<y.S.S<<"\n";
        }
      }
    }
  }
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}