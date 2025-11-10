#define ll long long
#define vll vector<ll>
// Persistent seg tree for range sum querries
const int N = 2e5+5;
int roots[N], curr = 1;
struct Node{ ll val; int l, r; };
Node st[22*N];
const int NEUT = 0;
// query(0, n-1, a)
int build(int l, int r, vll &a){
  if (l == r){
    st[++curr].val=(l<a.size())?a[l]:NEUT;
    return curr;
  }
  int m = l+(r-l)/2;
  int p = ++curr;
  st[p] = {
    0, build(l, m, a), build(m+1, r, a)
  };
  st[p].val=st[st[p].l].val+st[st[p].r].val;
  return p;
}
// query(root[k], 0, n-1, pos, x)
int update(int i,int l,int r,int k,ll x){
  if (l == r){
    st[++curr].val = x; return curr;
  }
  int m = l+(r-l)/2;
  int p = ++curr;
  if (k <= m){
    st[p] = {
      0, update(st[i].l, l, m, k, x),
      st[i].r
    };
  } else {
    st[p] = {0, st[i].l,
    update(st[i].r, m+1, r, k, x)
  };
  }
  st[p].val=st[st[p].l].val+st[st[p].r].val;
  return p;
}
// query(root[k], 0, n-1, l, r)
ll query(int i,int l,int r,int tl,int tr){
  if (l > tr || r < tl) return NEUT;
  if (tl <= l && r <= tr) return st[i].val;
  int m = l+(r-l)/2;
  return query(st[i].l, l, m, tl, tr) +
    query(st[i].r, m+1, r, tl, tr);
}