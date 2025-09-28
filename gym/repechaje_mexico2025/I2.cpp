#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> p(n-1);
  int lstx, lsty; cin>>lstx>>lsty;
  for(int i  =0; i < n-1; i++){
    int x, y; cin>>x>>y;
    if(x==lstx){
      p[i] = abs(lsty-y);
    }else{
      p[i] = abs(lstx-x);
    }
    lstx  = x;
    lsty = y;
  }
  int l=0, r=2e9; 
  for(int i = n-2; i >= 0; i--){
    int d = p[i];
    if(l>=d){
      cout<<"-1\n";
      return 0;
    }
    if(r >= d){
      r = min(d - l, d - 1);
      l = 1;
      continue;
    }
    l = d  - l;
    r = d  - r; 
    if(l>r) swap(l,r);
    l = max(l,1);
    r = min(d-1, r);

  }
  cout<<r<<"\n";
  return 0;
}