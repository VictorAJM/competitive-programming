#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rev(x) reverse(x)
#define pb(x) push_back(x)
#define sz(x) x.size()
#define FOR(i, a) for (int i=0;i<a;i++)

using namespace std;

const int N = 755;
const int mod = 1e9+7;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;

int st[16*N*N];
int n,m,a[N][N];

void init(int no, int ix, int iy, int fx, int fy) {
  if (ix==fx && iy == fy) {
    st[no] = a[ix][iy];
    return;
  }
  if (ix>fx || iy>fy) {
    st[no]=0;
    return;
  }
  int mx = (ix+fx)/2;
  int my = (iy+fy)/2;
  init(no*4+1,ix,iy,mx,my);
  init(no*4+2,ix,my+1,mx,fy);
  init(no*4+3,mx+1,iy,fx,my);
  init(no*4+4,mx+1,my+1,fx,fy);
  st[no] = max({st[no*4+1], st[no*4+2],st[no*4+3],st[no*4+4]});
  return;
}
int ipx;
int ipy;
int fpx; 
int fpy;
int get(int no, int ix, int iy, int fx, int fy) {
  if (ix>fx || iy>fy) {
    return 0;
  }
  if (ipx <= ix && fx <= fpx && ipy <= iy && fy <= fpy) {
    return st[no];
  }
  if (ix > fpx || fx < ipx || iy > fpy || fy < ipy) {
    return 0;
  }
  int mx = (ix+fx)/2;
  int my = (iy+fy)/2;
  // , ipx, ipy, fpx, fpy
  return max({
  get(no*4+1,ix,iy,mx,my),
  get(no*4+2,ix,my+1,mx,fy),
  get(no*4+3,mx+1,iy,fx,my),
  get(no*4+4,mx+1,my+1,fx,fy)});
}

void solve() {
  cin >> n >> m;
  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j];
  init(0,1,1,n,m);
  ll cnt = 0;
  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
  for (int q=i+1;q<=n;q++) for (int w=j+1;w<=m;w++) {
    int val = min({a[i][j], a[q][w], a[i][w], a[q][j]});
    ipx = i+1;
    ipy = j;
    fpx = q-1;
    fpy = w;
    int get1 = get(0,1,1,n,m);
    ipx = i;
    ipy = j+1;
    fpx = q;
    fpy = w-1;
    int get2 = get(0,1,1,n,m);
    if (val > max(get1, get2)) {
      cnt++;
    }
  }
  cout << cnt << "\n";
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int t =1;
  while (t--) solve();
  return 0;
}