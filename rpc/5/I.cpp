#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

void solve() {
  int a[5];
  int n;
  cin >> n;
  int b[5];
  int x=0,y=0,z=0;
  for (int j=0;j<5;j++) a[j]=-1;
  for (int i=1;i<=n;i++) {
    int p=0;
    for (int j=0;j<5;j++) {
      cin >> b[j];
      if (b[j]>a[j]) p++;
    }
    for (int j=0;j<5;j++) a[j]=max(b[j], a[j]);
    if (p==3) x++;
    if (p==4) y++;
    if (p==5) z++;
  }
  cout << x << " "<<y<<" "<<z<<"\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  solve();
  return 0;
}