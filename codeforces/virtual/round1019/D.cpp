#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define F first
#define S second

using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;
using vii = vector<ii>;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vvi g(23);
  for (int i=0;i<n;i++) if (a[i] > 0) g[a[i]].pb(i);
  int q=1, w=n;
  vi ans(n+1,0);
  int p = 0;
  for (int i=0;i<n;i++) if (a[i]== -1) p=i;
  for (int i=1;i<23;i++) {
    if (i%2==1) {
      int j = 0;
      int J = g[i].size()-1;
      if (J>=0) {
        if (p<g[i][j]) {
          for (int k=J;k>=0;k--) {
              ans[g[i][k]] = w--;

          }
        } else if (p>g[i][J]) {
          for (int k=0;k<g[i].size();k++) {
              ans[g[i][k]] = w--;
          }
        } else {
          for (int k=0;k<g[i].size()&&g[i][k]<p;k++) {
              ans[g[i][k]] = w--;
          }
          for (int k=g[i].size()-1;k>=0&&g[i][k]>p;k--) {
              ans[g[i][k]] = w--;
          }
        }
      }
    } else {
      int j = 0;
      int J = g[i].size()-1;
      if (J>=0) {
        if (p<g[i][j]) {

        for (int k=J;k>=0;k--) {
          ans[g[i][k]] = q++;
        }
        } else if (p>g[i][J]) {

          for (int k=0;k<g[i].size();k++) {
            ans[g[i][k]] = q++;
        
        }
        } else {
          for (int k=0;k<g[i].size()&&g[i][k]<p;k++) {
              ans[g[i][k]] = q++;
          }
          for (int k=g[i].size()-1;k>=0&&g[i][k]>p;k--) {
              ans[g[i][k]] = q++;
          }
        }
      }
    }
  }
  for (int i=0;i<n;i++) {
    if (ans[i]==0) {
      ans[i]=q++;
    }
  }
  for (int i=1;i<=n;i++) {
    cout << ans[i-1] << " ";
  }
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}
