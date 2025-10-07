#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,k;
  cin >> a >> b >> k;
  if (b==1) {
    if (k == 0) {
      cout<<"Yes\n";
      cout<<"1";
      for (int i=1;i<=a;i++) cout<<"0";
      cout << "\n";
      cout<<"1";
      for (int i=1;i<=a;i++) cout<<"0";
      cout << "\n";
    } else {
      cout << "No\n";
    }
    return 0;
  }
  if (k>a) {
    cout<<"No\n";
    return 0;
  }
  cout<<"Yes\n";
  for (int i=1;i<=b;i++) cout<<"1";
  for (int i=1;i<=a;i++) cout<<"0";
  cout<<"\n";
  cout<<"1";
  for (int i=1;i<=k;i++) cout<<"0";
  cout<<"1";
  for (int i=1;i<=b-2;i++) cout<<"1";
  for (int i=1;i<=a-k;i++) cout<<"0";
  cout<<"\n";
}