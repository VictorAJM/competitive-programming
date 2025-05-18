#include <bits/stdc++.h>
#define all(s) s.begin(), s.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int _N = 1e5 + 5;

int T;

void solve() {
	int n; cin >> n;
	vector<ll> a(n); ll sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	if (sum % n) return cout << "No" << '\n', void();
	sum /= n;
	vector<int> bit(31, 0);
	auto lowbit = [](int x) {
	    return x & (-x);
	};
	for (int i = 0; i < n; i++) {
		if (a[i] == sum) continue;
		int d = abs(a[i] - sum);
		int p = lowbit(d);
		int e = d + p;
		if (__builtin_popcount(e) == 1) {
		    if (a[i] > sum) bit[__lg(e)]++, bit[__lg(p)]--;
		    else bit[__lg(e)]--, bit[__lg(p)]++;
		} else {
		    cout << "No" << '\n';
		    return;
		}
	}
	for (int i = 0; i < 31; i++) {
		if (bit[i]) {
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
}