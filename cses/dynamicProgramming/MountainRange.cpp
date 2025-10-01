#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int N = 2e5+5;

int n,a[N];

int st[4*N];

int get(int no, int i, int f, int l, int r) {
  if (i > r || f < l) return 0;
  if (l <= i && f <= r) return st[no];
  int mid = (i+f)/2;
  return max(get(no*2+1,i,mid,l,r), get(no*2+2,mid+1,f,l,r));
}

void upd(int no, int i, int f, int p, int v) {
  if (p < i || f < p) return;
  if (i==f) {
    st[no] = v;
    return;
  }
  int mid = (i+f)/2;
  upd(no*2+1,i,mid,p,v);
  upd(no*2+2,mid+1,f,p,v);
  st[no] = max(st[no*2+1], st[no*2+2]);
  return;
}


int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];

  stack<pair<int,int>> s;
  int ans = 0;

  for (int i=n-1;i>=0;i--) {
    while (s.size()>0 && a[i] > s.top().F) {
      s.pop();
    }

    int pos = n-1;
    if (s.size()>0) pos = s.top().S-1;

    int cur = get(0,0,n-1,i,pos);
    cout << pos <<"?" <<cur+1 << "\n";
    ans = max(ans,cur+1);

    upd(0,0,n-1,i,cur+1);

    s.push({a[i], i});
  }
  cout << ans << "\n";
  return 0;
}