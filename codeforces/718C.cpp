#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
using ll = long long;
struct mat {
  ll a[2][2] = {{0,0}, {0,0}};
};

mat operator * (mat A, mat B) {
  mat C;
  for (int i=0;i<2;i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++) {
    C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j])%mod;
  }
  return C;
}
mat operator + (mat A, mat B) {
  mat C;
  for (int i=0;i<2;i++) for (int j=0;j<2;j++) {
    C.a[i][j] = (A.a[i][j] + B.a[i][j])%mod;
  }
  return C;
}
mat mpow(mat A, ll _pow) {
  mat R;
  for (int i=0;i<2;i++) R.a[i][i] = 1;
  while (_pow) {
    if (_pow&1) R = R*A;
    A = A*A;
    _pow >>= 1;
  }
  return R;
}
mat fib(ll _pow) {
  mat A;
  A.a[0][0] = 1;
  A.a[0][1] = 1;
  A.a[1][0] = 1;
  return mpow(A, _pow);
}

struct SegTree {
  mat t,s;
} st[4*N];
ll a[N],n,m;

void push(int no) {
  st[no*2].t = st[no*2].t * st[no].t;
  st[no*2+1].t = st[no*2+1].t * st[no].t;

  st[no*2].s = st[no*2].s * st[no].t;
  st[no*2+1].s = st[no*2+1].s * st[no].t;
  mat R;
  for (int i=0;i<2;i++) R.a[i][i] = 1;
  st[no].t = R;
}
void upd(int no, int in, int fi, int l, int r, mat x) {
  if (fi < l || r < in) return;
  if (l <= in && fi <= r) {
    st[no].t = st[no].t * x;
    st[no].s = st[no].s * x;
    return;

  }
  push(no);
  int m = (in+fi)/2;
  upd(no*2,in,m,l,r,x);
  upd(no*2+1,m+1,fi,l,r,x);
  st[no].s = st[no*2].s + st[no*2+1].s;
}
mat get(int no, int in, int fi, int l, int r) {
  mat C;
  if (fi < l || r < in) return C;
  if (l <= in && fi <= r) {
    return st[no].s;
  }
  push(no);
  int m = (in+fi)/2;
  mat a = get(no*2,in,m,l,r) + get(no*2+1,m+1,fi,l,r);
  return a;
}
void init(int no,int in, int fi) {
  if (in==fi) {
    st[no].s = fib(a[in]);
    mat R;
    for (int i=0;i<2;i++) R.a[i][i] = 1;
    st[no].t = R;
    return;
  }
  int m = (in+fi)/2;
  init(no*2,in,m);
  init(no*2+1,m+1,fi);
  st[no].s = st[no*2].s + st[no*2+1].s;
  mat R;
  for (int i=0;i<2;i++) R.a[i][i] = 1;
  st[no]. t = R;
}
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i=1;i<=n;i++) cin >> a[i];
  init(1,1,n);
  while (m--) {
    int t,l,r,x;
    cin >> t >> l >> r;
    if (t==1) cin >> x;

    if (t==1) {
      upd(1,1,n,l,r,fib(x));
    } else {
      cout << get(1,1,n,l,r).a[0][1] << "\n";
    }
  }
  return 0;
}