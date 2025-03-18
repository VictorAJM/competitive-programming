#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
using ll = long long;
ll st[4*N], cnt[4*N],n,m,a[N];
ll gg[1000005];
void init(int no, int in, int fi) {
  if (in==fi) {
    st[no] = a[in];
    cnt[no] = (a[in] >= 3);
    return;
  }
  int m = (in+fi)/2;
  init(no*2, in, m);
  init(no*2+1, m+1, fi);
  st[no] = st[no*2] + st[no*2 + 1];
  cnt[no] = cnt[no*2] + cnt[no*2 + 1];
  return; 
}
void _upd(int no, int in, int fi) {
  if (cnt[no]==0) return;
  if (in == fi) {
    st[no] = gg[st[no]];
    cnt[no] = (st[no]>=3);
    return;
  }
  int m = (in+fi)/2;
  _upd(no*2, in, m);
  _upd(no*2+1, m+1, fi);
  st[no] = st[no*2]+st[no*2+1];
  cnt[no] = cnt[no*2]+ cnt[no*2+1];
}
void upd(int no, int in, int fi, int l, int r) {
  if (fi < l || r < in) return;
  if (l <= in && fi <= r) {
    if (cnt[no]>0) _upd(no, in, fi);
    return;
  }
  int m = (in+fi)/2;
  upd(no*2, in, m, l, r);
  upd(no*2+1, m+1, fi, l, r);
  st[no] = st[no*2]+st[no*2+1];
  cnt[no] = cnt[no*2]+ cnt[no*2+1];
  return;
}

ll sum(int no, int in, int fi, int l, int r) {
  if (fi < l || r < in) return 0;
  if (l <= in && fi <= r) {
    return st[no];
  }
  int m = (in+fi)/2;
  return   sum(no*2, in, m, l, r) + 
  sum(no*2+1, m+1, fi, l, r);
}

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  for (int i=1;i<=1000000;i++) {
    for (int j=i;j<=1000000;j+=i) gg[j]++;
  }
  cin >> n >> m;
  for (int i=1;i<=n;i++) cin >> a[i];
  init(1,1,n);
  while (m--) {
    int t,l,r;
    cin >> t >> l >> r;
    if (t==1) upd(1,1,n,l,r);
    else cout << sum(1,1,n,l,r) << "\n";
  }
  return 0;
}