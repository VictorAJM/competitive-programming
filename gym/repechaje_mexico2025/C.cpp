#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int m  = 1000;
  vector<int> p(m+5, 0);
  long long a = 0;
  long long b = 1;
  for(int i = 0; i <= n; i++){
    cin>>p[i];
  }
  for(int i = n; i >= 0; i--){
    if (p[i]) a+=b;
    b *= 2;
  }
  int cnt =0 ;
  while (a>1) {
    if (a%2==0) a /= 2;
    else a = a^(a+a+1);
    cnt++;
  }
  cout << cnt <<"\n";
  return 0;
}