#include <bits/stdc++.h>
using namespace std;

int st[16000505], lz[16000505];

void push(int no, int i, int f) {
  
    lz[no*2] += lz[no];
    st[no*2] += lz[no];

    lz[no*2+1] += lz[no];
    st[no*2+1] += lz[no];

    lz[no] = 0;
  
}

void  add(int no, int i, int f,int l,int r, int k) {
  if (f < l || r < i) return;
  if (l <= i && f <= r) {
    
    lz[no] += k;
    st[no] += k;
    return;
  }
  push(no, i, f);
  int mid = (i+f)/2;
  add(no*2,i,mid,l,r,k);
  add(no*2+1,mid+1,f,l,r,k);
  st[no] = max(st[no*2], st[no*2+1]);
}

void add(int val, int k=-1) {
  add(1,0,2000000,val,2000000,k);
}

void remove(int val) {
  add(val, 1);
}

int get(int no, int i, int f,int l,int r) {
  if (f < l || r < i) return -1;
  if (l <= i && f <= r) {
    return st[no];
  }
  push(no, i, f);
  int mid = (i+f)/2;
  int L = get(no*2, i,mid,l,r);
  int R = get(no*2+1,mid+1,f,l,r);

  st[no] = max(st[no*2], st[no*2+1]);
  return max(L,R);
}

int get(int l, int r) {
  return get(1,0,2000000,l,r);
}

int check(int m) {
  int xd = get(0,m);
  if (xd < 0) return true;
  return false;
}

int get() {
  int l = 0; int r = 2000000;
  while (r-l > 1) {
    
    int m = (l+r)/2;
  
    if (check(m)) l = m;
    else r = m;
  }
  return l;
}

void ini(int no, int i, int f) {
  if (i==f) {
    st[no] = i;
    return;
  }
  int mid = (i+f)/2;
  ini(no*2,i,mid);
  ini(no*2+1,mid+1,f);
  st[no] = max(st[no*2], st[no*2+1]);
} 

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  int A,D,n;
  cin >> A >> D;
  cin >> n;
  vector<int> a(n), d(n);
  for (int& i:a) cin >> i;
  for (int& i:d) cin >> i;
  vector<int> c(n);
  for (int i=0;i<n;i++) c[i] = max(a[i]-A, 0) + max(d[i]-D, 0);
  ini(1,0,2000000);

  for (int i=0;i<n;i++){

    add(c[i]);

  }


  int m;
  cin >> m;
  while (m--) {
    int k,na, nd;
    cin >> k >> na >> nd;
    remove(c[k-1]);
    a[k-1] = na; d[k-1] = nd;
    c[k-1] = max(a[k-1] - A, 0) + max(d[k-1]-D, 0);
    add(c[k-1]);
    if (!check(0)) cout << "0\n";
    else 
    cout << get()+1 << "\n";
  }
  return 0;
}