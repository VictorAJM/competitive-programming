#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  int cnt = n/2;
  for (int i : a) if ((int)sqrt(i)*(int)sqrt(i) == i) {
    cnt--;
  }
  if (cnt<=0) {
    vector<int> b;
    for (int i:a)   if ((int)sqrt(i)*(int)sqrt(i) == i) { if (i==0) b.push_back(2); else b.push_back(1); }
    sort(b.begin(),b.end());
    long long sum = 0;
    cnt*=-1;
    for (int i=0;i<cnt;i++) sum += b[i];
    cout<<sum<<"\n";
    return 0;
  }
  vector<int> b;
  for (int i:a)  if ((int)sqrt(i)*(int)sqrt(i) != i) {
    b.push_back(min(i - (int)sqrt(i)*(int)sqrt(i), ((int)sqrt(i)+1)*((int)sqrt(i)+1) - i));
  }
  sort(b.begin(),b.end());
  long long sum = 0;
  for (int i=0;i<cnt;i++) sum += b[i];
  cout<<sum<<"\n";
  return 0;
}