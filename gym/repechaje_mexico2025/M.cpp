#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  multiset<long long> l, r, m;
  for(int i=0; i<n; i++){ cin >> a[i]; r.insert(a[i]);}
  long long ans = *r.begin();

  for(int i=0; i<n; i++){
    r.erase(r.find(a[i]));
    m.insert(a[i]+k+i);
    if(i-k >= 0){
      m.erase(m.find(a[i-k]+i));
      l.insert(a[i-k]);
    }
    long long x = (*m.begin()) - i;
    if(l.size()) x = min(x, *l.begin());
    if(r.size()) x = min(x, *r.begin());
    ans = max(ans, x);
  }
  cout << ans << '\n';
}