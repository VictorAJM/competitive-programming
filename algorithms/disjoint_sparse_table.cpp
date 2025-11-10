// Find any asociative function on a range
// in O(1) time.
// MAX2 = log(MAXN)
//
// build - O(n log(n))
// query - O(1)

struct DST {
  int m[MAX2][1<<MAX2], n, v[1<<MAX2];
  int op(int a, int b) { return min(a, b); }
  DST(int n, int* v2) : n(n) {
    for (int i = 0; i < n; i++) v[i] = v2[i];
    while (n&(n-1)) n++;
    for (int j = 0; (1<<j) < n; j++) {
      int len = 1<<j;
      for (int c = len; c < n; c += 2*len) {
        m[j][c] = v[c], m[j][c-1] = v[c-1];
        for (int i = c+1; i <  c+len; i++)
          m[j][i] = op(m[j][i-1], v[i]);
        for (int i = c-2; i >= c-len; i--)
          m[j][i] = op(v[i], m[j][i+1]);
      }
    }
  }
  int query(int l, int r) {
    if (l == r) return v[l];
    int j = __builtin_clz(1) -
      __builtin_clz(l^r);
    return op(m[j][l], m[j][r]);
  }
};