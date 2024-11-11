#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n,b,c;
  cin>>n>>b>>c;
  if (b==0) {
    if (c==0) {
      if (n>2) cout<<"-1\n";
      else if (n==1) cout<<"0\n";
      else cout<<"1\n";
      return;
    } else {
      if (c>=n) cout<<n<<"\n";
      else if (c+2 >= n) cout <<n-1<<"\n";
      else cout<<"-1\n";
      return;
    }
  }
  if (c>=n) {
    cout<<n<<"\n";
    return;
  }
  long long z = n-c;
  z /= b;
  if (c+b*z == n) z--;
  cout << n-z-1<<"\n";
}
int main() {
  int t;
  cin>>t;
  while (t--) solve();
}