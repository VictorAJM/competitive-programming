#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> count_interesting_pairs(int t, vector<pair<vector<long long>, pair<int, pair<long long, long long>>>>& test_cases) {
    vector<long long> results;

    for (auto& test_case : test_cases) {
        vector<long long>& a = test_case.first;
        long long n = test_case.second.first;
        long long x = test_case.second.second.first;
        long long y = test_case.second.second.second;

        long long S = 0;
        for (long long val : a) {
            S += val;
        }

        long long L = S - y;
        long long R = S - x;

        sort(a.begin(), a.end());
        long long count = 0;

        for (long long i = 0; i < n; i++) {
            auto lower = lower_bound(a.begin() + i + 1, a.end(), L - a[i]);
            auto upper = upper_bound(a.begin() + i + 1, a.end(), R - a[i]);
            count += (upper - lower);
        }

        results.push_back(count);
    }

    return results;
}

int main() {
    int t;
    cin >> t;

    vector<pair<vector<long long>, pair<int, pair<long long, long long>>>> test_cases;

    for (int i = 0; i < t; i++) {
        long long n, x, y;
        cin >> n >> x >> y;
        vector<long long> a(n);

        for (long long j = 0; j < n; j++) {
            cin >> a[j];
        }

        test_cases.push_back({a, {n, {x, y}}});
    }

    vector<long long> results = count_interesting_pairs(t, test_cases);

    for (long long res : results) {
        cout << res << endl;
    }

    return 0;
}
