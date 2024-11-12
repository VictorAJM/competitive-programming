#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m;
struct ST {
  #define lc ((no*2)+1)
  #define rc ((no*2)+2)

  int st[4*N], lazy[4*N];

  void push(int no, int in, int fi) {
    if (lazy[no]>0) {
      st[no] = (fi-in+1);
      if (in!=fi) lazy[lc] = lazy[rc] = lazy[no];
    } else if (lazy[no]<0) {
      st[no] = 0;
if (in!=fi) lazy[lc] = lazy[rc] = lazy[no];
    }

    lazy[no] = 0;
  }

  void insert(int no, int in , int fi, int l, int r) {
    push(no,in,fi);
    if (r<in || fi<l) return;
    if (l <= in && fi <= r) {
      lazy[no] = 1;
      st[no] = (fi-in+1);

      return;
    }
    int m = (in+fi)/2;
    insert(lc,in,m,l,r);
    insert(rc,m+1,fi,l,r);
    if (in!=fi) st[no] = st[lc] + st[rc];
  }
  void insert(int l, int r) {
    insert(0,0,n-1,l,r);
  }

  void clear(int no, int in, int fi, int l,int r) {
    push(no,in,fi);
    if (r<in || fi<l) return;
    if (l <= in && fi <= r) {
      lazy[no] = -1;
      st[no] = 0;
      return;
    }
    int m = (in+fi)/2;
    clear(lc,in,m,l,r);
    clear(rc,m+1,fi,l,r);
    if (in!=fi) st[no] = st[lc] + st[rc];
  }

  void clear(int l,int r) {
    clear(0,0,n-1,l,r);
  }

  int count(int no, int in,int fi,int l,int r) {
    push(no,in,fi);
    if (r<in || fi<l) return 0;
    if (l <= in && fi <= r) return st[no];
    int m = (in+fi)/2;
    int ans = count(lc,in,m,l,r) + count(rc,m+1,fi,l,r);
    if (in!=fi) st[no] = st[lc] + st[rc];
    return ans;
  }

  int count(int l, int r) {
    return count(0,0,n-1, l, r);
  }


} st[27];
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);

  cin >> n >> m;
  string s;
  cin>>s;
  for (int j=0;j<26;j++) st[j].clear(0,n-1), st[j].lazy[0]=-1;
  for (int i=0;i<n;i++) {
    st[s[i]-'a'].insert(i,i);
  }
  for (int i=0;i<m;i++) {
    int l,r,k;
    cin>>l>>r>>k;
    if (k==1) {
      int cnt[27];
      for (int j=0;j<26;j++) cnt[j] = st[j].count(l-1,r-1);

      int pos=l-1;
      for (int j=0;j<26;j++)  st[j].clear(l-1,r-1);
      for (int j=0;j<26;j++)  {
        if (cnt[j]>0)  st[j].insert(pos,pos+cnt[j]-1);
        pos+=cnt[j];
      }
    } else {
      int cnt[27];
      for (int j=0;j<26;j++) cnt[j] = st[j].count(l-1,r-1);
      int pos=r-1;
      for (int j=0;j<26;j++)  st[j].clear(l-1,r-1);
      for (int j=0;j<26;j++) {
        if (cnt[j]>0) st[j].insert(pos-cnt[j]+1,pos);
        pos-=cnt[j];
      }

    }
  }
  
  for (int i=0;i<n;i++) {
    for (int j=0;j<26;j++) if (st[j].count(i,i))  {
      cout<<(char)('a'+j);
      j=30;
    }
  }
}