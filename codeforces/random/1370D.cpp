#include <bits/stdc++.h>
using namespace std;
bool check_odd(int m, int k, vector<int>& a) {
  int j=0;
  int n = a.size();
  for (int i=0;i<k;i++) {
    if (i%2==0) {
      while (j<n && a[j]>m) j++;
      if (j==n) return false;
      j++;
    } else {
      if (j==n) return false;
      j++;
    }
  }
  return true;
}
bool check_even(int m, int k, vector<int>& a) {
  int j=0;
  int n = a.size();
  for (int i=0;i<k;i++) {
    if (i%2==1) {
      while (j<n && a[j]>m) j++;
      if (j==n) return false;
      j++;
    } else {
      if (j==n) return false;
      j++;
    }
  }
  return true;
}
int main() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int& i:a) cin >> i;
  int odd_l = 0, odd_r = 1000000000;
  while (odd_l+1 < odd_r) {
    int m = (odd_l+odd_r)/2;
    if (check_odd(m,k,a)) odd_r = m;
    else odd_l = m;
  }
  int even_l = 0, even_r = 1000000000;
  while (even_l+1 < even_r) {
    int m = (even_l+even_r)/2;
    if (check_even(m,k,a)) even_r = m;
    else even_l = m;
  }
  cout << min(odd_r, even_r) << "\n";
}