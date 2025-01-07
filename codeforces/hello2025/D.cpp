#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<int,int>;
const int N = 2e5+5;
struct i3 {
  int ans;
  int min;
  int max;
};
i3 st[4*N],st2[4*N];
void init(int no, int in, int fi,vector<int>& a) {
  if (in==fi) {
    st[no].ans = 0;
    st[no].min = a[in];
    st[no].max = a[in];
    return;
  }
  int mid = (in+fi)/2;
  init(no*2+1,in,mid,a); init(no*2+2,mid+1,fi,a);
  st[no].ans = max(st[no*2+1].ans, st[no*2+2].ans);
  st[no].min = min(st[no*2+1].min, st[no*2+2].min);
  st[no].max = max(st[no*2+1].max, st[no*2+2].max);
  if (st[no*2+1].max - st[no*2+2].min > st[no].ans) 
    st[no].ans = st[no*2+1].max - st[no*2+2].min;
  return;
}
void init2(int no, int in, int fi,vector<int>& a) {
  if (in==fi) {
    st2[no].ans = 0;
    st2[no].min = a[in];
    st2[no].max = a[in];
    return;
  }
  int mid = (in+fi)/2;
  init2(no*2+1,in,mid,a); init2(no*2+2,mid+1,fi,a);
  st2[no].ans = max(st2[no*2+1].ans, st2[no*2+2].ans);
  st2[no].min = min(st2[no*2+1].min, st2[no*2+2].min);
  st2[no].max = max(st2[no*2+1].max, st2[no*2+2].max);
  if (st2[no*2+2].max - st2[no*2+1].min > st2[no].ans) 
    st2[no].ans = st2[no*2+2].max - st2[no*2+1].min;
  return;
}
int ans() {
  return st[0].ans;
}
int ans2() {
  return st2[0].ans;
}
void upd(int no, int in,int fi,int pos, int val) {
  if (fi < pos || pos<in) return;
  if (in == fi) {
    st[no].ans = 0;
    st[no].min = val;;
    st[no].max = val;
    return;
  }
  int mid = (in+fi)/2;
  upd(no*2+1,in,mid,pos,val); upd(no*2+2,mid+1,fi,pos,val);
  st[no].ans = max(st[no*2+1].ans, st[no*2+2].ans);
  st[no].min = min(st[no*2+1].min, st[no*2+2].min);
  st[no].max = max(st[no*2+1].max, st[no*2+2].max);
  if (st[no*2+1].max - st[no*2+2].min > st[no].ans) 
    st[no].ans = st[no*2+1].max - st[no*2+2].min;
  return;
}
void upd2(int no, int in,int fi,int pos, int val) {
  if (fi < pos || pos<in) return;
  if (in == fi) {
    st2[no].ans = 0;
    st2[no].min = val;;
    st2[no].max = val;
    return;
  }
  int mid = (in+fi)/2;
  upd2(no*2+1,in,mid,pos,val); upd2(no*2+2,mid+1,fi,pos,val);
  st2[no].ans = max(st2[no*2+1].ans, st2[no*2+2].ans);
  st2[no].min = min(st2[no*2+1].min, st2[no*2+2].min);
  st2[no].max = max(st2[no*2+1].max, st2[no*2+2].max);
  if (st2[no*2+2].max - st2[no*2+1].min > st2[no].ans) 
    st2[no].ans = st2[no*2+2].max - st2[no*2+1].min;
  return;
}
void solve() { 
  int n,q;
  cin>>n>>q;
  vector<int> a(n+1),b(n+1);
  for (int i=1;i<=n;i++) cin>>a[i];

  for (int i=1;i<=n;i++) b[i] = a[i]-i;
  for (int i=1;i<=n;i++) a[i] = a[i]+i;
  init(0,1,n,a);
  init2(0,1,n,b);
  cout<<max({ans(), ans2(), 0})<<"\n";
  for (int i=1;i<=q;i++) {
    int p,x;
    cin>>p>>x;
    upd(0,1,n,p,x+p);
    upd2(0,1,n,p,x-p);
    cout<<max({ans(), ans2(), 0})<<"\n";
  }
}
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  while (t--) solve();
  return 0;
}