#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p > y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
} cht;
int main() {
  cin.tie(0)->ios_base::sync_with_stdio(0);
  ll n;
  cin>>n;
  vector<ll> dp(n);
  vector<pair<ll,pair<ll,ll>>> a(n);
  for (int i=0;i<n;i++) cin >> a[i].F >> a[i].S.F >> a[i].S.S;
  sort(a.begin(), a.end());
  cht.add(0,0);
  for (int i=0;i<n;i++) {
 
    dp[i] = max(cht.query(a[i].S.F), 0ll) - a[i].S.S + a[i].S.F*a[i].F;
 
    cht.add(-a[i].F,dp[i]);
 
  }
  cout << *max_element(dp.begin(), dp.end()) ;
}