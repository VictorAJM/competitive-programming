#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
ll solve(ll l, ll r, vector<ll>& a, vector<ll>& sum, vector<vector<ii>>& STEPS) {
  ll ans = 0;
  ll len = r - l+1;
  for (int i=19;i>=0;i--) {
    if (STEPS[l][i].S <= len) {
      ans += STEPS[l][i].F;
      len -= STEPS[l][i].S;
      l += STEPS[l][i].S;
    }
  }
  if (len > 1) {
    len--;
    ans += (len * a[l] - sum[r] + sum[l]);
  }
  return ans;
}
int main() {             
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for(ll& i:a) cin >> i;
  vector<ll> sum(n+1);
  sum[0] = a[0];
  for(int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  sum[n] = sum[n-1];
  vector<ll> step(n+1);
  vector<ll> stepLen(n+1);
  stack<ii> s;
  for (int i=n-1;i>=0;i--) {
    while(!s.empty() && s.top().F < a[i]) {
      s.pop();
    }
    if(s.empty()) {
      step[i] = (n - i-1) * a[i] - sum[n-1] + sum[i];
      stepLen[i] = n - i;
    } else {
      step[i] = (s.top().S - i-1) * a[i] - sum[s.top().S-1] + sum[i];
      stepLen[i] = s.top().S - i;
    }
    s.push({a[i], i});
  }
  step[n] = stepLen[n] = 0;
  vector<vector<ii>> STEPS(n+1, vector<ii>(20, {0,0}));
  for (int i=n;i>=0;i--) {
    STEPS[i][0] = {step[i], stepLen[i]};
    for (int j=1;j<20;j++) {
      STEPS[i][j] = {STEPS[i][j-1].F + STEPS[i + STEPS[i][j-1].S][j-1].F, STEPS[i][j-1].S + STEPS[i + STEPS[i][j-1].S][j-1].S};
    }
  }
  while(q--) {
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << solve(l, r, a, sum, STEPS) << '\n';
  }
  return 0;
}