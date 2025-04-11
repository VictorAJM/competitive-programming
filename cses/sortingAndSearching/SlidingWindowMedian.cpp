#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (k == 1) {
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    return 0;
  }
  if (k == 2) {
    for (int i = 0; i < n - 1; i++) {
      cout << min(a[i], a[i + 1])<< ' ';
    }
    return 0;
  }
  multiset<int> left, right;

  vector<int> aux;
  for (int i=0;i<k;i++) aux.push_back(a[i]);
  sort(aux.begin(), aux.end());

  for (int i=0;i<(k+1)/2;i++) left.insert(aux[i]);
  for (int i=(k+1)/2;i<k;i++) right.insert(aux[i]);
  cout << *left.rbegin() << ' ';
  for (int i=k;i<n;i++) {
    int val = a[i-k];
    if (left.count(val)) {
      left.erase(left.find(val));
    } else {
      right.erase(right.find(val));
    }
    if ((!left.empty() && a[i] <= *left.rbegin()) || (!right.empty() && a[i] < *right.begin())) {
      left.insert(a[i]);
    } else {
      right.insert(a[i]);
    }
    if (left.size() < right.size()) {
      left.insert(*right.begin());
      right.erase(right.find(*right.begin()));
    }
    if (left.size() > right.size()+1) {
      right.insert(*left.rbegin());
      left.erase(left.find(*left.rbegin()));
    }
    cout << *left.rbegin() << ' ';

  }
  return 0;
}