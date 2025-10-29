#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
const int N = 1200300;
 
int n, m;
int c[N];
vector<int> g[N];
pair<int, pt> q[N];
 
inline bool read() {
    if (!(cin >> n >> m)) return false;
    forn(i, n) assert(scanf("%d", &c[i]) == 1);
    forn(i, n) g[i].clear();
    forn(i, n - 1) {
        int x, y;
        assert(scanf("%d%d", &x, &y) == 2);
        x--, y--;
        g[x].pb(y), g[y].pb(x);
    }
    forn(i, m) {
        assert(scanf("%d%d", &q[i].x, &q[i].y.x) == 2);
        q[i].y.x--;
        if (q[i].x == 1) {
            assert(scanf("%d", &q[i].y.y) == 1);
            //q[i].y.y--;
        }
    }
    return true;
}
 
int tt, tin[N], tout[N], vs[N];
 
void dfs(int v, int p) {
    vs[tt] = v;
    tin[v] = tt++;
    forn(i, sz(g[v])) if (g[v][i] != p) dfs(g[v][i], v);
    tout[v] = tt;
}
 
li t[4 * N], add[4 * N];
 
void build(int v, int l, int r) {
    add[v] = -1;
    if (l + 1 == r) t[v] = 1ll << c[vs[l]];
    else {
        int md = (l + r) >> 1;
        build(2 * v + 1, l, md);
        build(2 * v + 2, md, r);
        t[v] = t[2 * v + 1] | t[2 * v + 2];
    }
}
 
inline void push(int v) {
    if (add[v] == -1) return;
    fore(i, 1, 3)
        t[2 * v + i] = add[2 * v + i] = add[v];
    add[v] = -1;
}
 
void paint(int v, int l, int r, int lf, int rg, int c) {
    if (lf >= rg) return;
    if (l == lf && r == rg) {
        t[v] = 1ll << c;
        add[v] = 1ll << c;
    } else {
        push(v);
        int md = (l + r) >> 1;
        paint(2 * v + 1, l, md, lf, min(md, rg), c);
        paint(2 * v + 2, md, r, max(lf, md), rg, c);
        t[v] = t[2 * v + 1] | t[2 * v + 2];
    }
}
 
li get(int v, int l, int r, int lf, int rg) {
    if (lf >= rg) return 0;
    if (l == lf && r == rg) return t[v];
    push(v);
    int md = (l + r) >> 1;
    li ans = 0;
    ans |= get(2 * v + 1, l, md, lf, min(md, rg));
    ans |= get(2 * v + 2, md, r, max(lf, md), rg);
    return ans;
}
 
inline void solve() {
    tt = 0;
    dfs(0, -1);
    assert(tt == n);
    build(0, 0, n);
 
    forn(i, m) {
        int tp = q[i].x, v = q[i].y.x;
        if (tp == 1) {
            int c = q[i].y.y;
            paint(0, 0, n, tin[v], tout[v], c);
        } else {
            li mask = get(0, 0, n, tin[v], tout[v]);
            /*cerr << mask << endl;
            cerr << v << ' ' << tin[v] << ' ' << tout[v] << endl;
            fore(i, tin[v], tout[v]) cerr << get(0, 0, n, i, i + 1) << ' '; cerr << endl;*/
            int ans = 0;
            forn(j, 61) ans += int((mask >> j) & 1);
            printf("%d\n", ans);
        }
    }
}
 
int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
 
    while (read()) {
        solve();
        //break;
    }
    
    return 0;
}