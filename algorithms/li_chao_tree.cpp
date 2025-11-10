// Supports line inserts (ax + b) on a range
// and querrys for the max value at some
// point. For min insert -a,-b use -Query()

#define ll long long

typedef ll data_t;
const data_t inf = 4e18; 
const data_t X_MIN = -1e9 - 1;
const data_t X_MAX = 1e9 + 1;

template<typename T>
struct Line {
  T a, b;
  Line() : a(0), b(-inf) {}
  Line(T a, T b) : a(a), b(b) {}
  T get(T x) {
    return a * x + b;
  }
};
struct Node {
  Line<data_t> line = Line<data_t>();
  Node *lc = nullptr;
  Node *rc = nullptr;
};
void InsertLineKnowingly(
  Node* &n,data_t tl,data_t tr,Line<data_t> x
) {
  if (n == nullptr) n = new Node();
  if (n->line.get(tl) < x.get(tl))
    swap(n->line, x);
  if (n->line.get(tr) >= x.get(tr)) return;
  if (tl == tr) return;
  data_t mid = (tl + tr) / 2;
  if (n->line.get(mid) > x.get(mid))
  InsertLineKnowingly(n->rc, mid + 1, tr, x);
  else {
    swap(n->line, x);
    InsertLineKnowingly(n->lc, tl, mid, x);
  }
}
void InsertLine(Node* &n, data_t tl,
data_t tr, data_t l, data_t r,
Line<data_t> x) {
  if (tr < l || r < tl || tl > tr || l > r)
    return;
  if (n == nullptr) n = new Node();
  if (l <= tl && tr <= r)
    return InsertLineKnowingly(n, tl, tr, x);
  data_t mid = (tl + tr) / 2;
  InsertLine(n->lc, tl, mid, l, r, x);
  InsertLine(n->rc, mid + 1, tr, l, r, x);
}
data_t Query(Node* &n, data_t tl,
data_t tr, data_t x) {
  if (n == nullptr) return -inf;
  if (tl == tr) return n->line.get(x);
  data_t res = n->line.get(x);
  data_t mid = (tl + tr) / 2;
  if (x <= mid)
    res = max(res, Query(n->lc, tl, mid, x));
  else
  res=max(res, Query(n->rc, mid + 1, tr, x));
  return res;
}

Node* root = nullptr;
void InsertLine(Line<data_t> x,
  data_t l=X_MIN, data_t r=X_MAX) {
  return InsertLine(root,X_MIN,X_MAX,l,r, x);
}
data_t Query(data_t x) {
  return Query(root, X_MIN, X_MAX, x);
}