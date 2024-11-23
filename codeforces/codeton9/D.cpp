#include <bits/stdc++.h>
using namespace std;
int count(long long n) {
    int count = 0;
    while (n % 2 == 0) {
      count++;
      n /= 2;
    }

    for (long long i = 3; i <= sqrt(n); i += 2) {
      while (n % i == 0) {
        count++;
        n /= i;
      }
    }

    if (n > 1) {
        count++;
    }

    return count;
}
void solve() {
  int n,m;
  cin>>n>>m;
  vector<int> a(m);
  vector<int> p(n+1);
  for(int& i:a) cin>>i;
  for (int i=1;i<=n;i++)  p[i]=count(i);
  for (int i=1;i<=n;i++) if (p[i] >= m) {
    cout<<"-1\n";
    return;
  }
  for (int i=1;i<=n;i++) cout<<a[m-p[i]-1]<<" ";
  cout << "\n";
}
int main() {
  int t;
  cin>>t;
  
  while (t--) solve();
}