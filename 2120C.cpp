#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        long long n, m;
        cin >> n >> m;
        if (n * (n+1) < m * 2) {
            cout << -1 << "\n";
            continue;
        }
        if (n > m) {
            cout << -1 << "\n";
            continue;
        }

        long long lo = 1;
        long long hi = n;
        while (lo < hi) {
            long long mid = (hi + lo) / 2;
            long long val = mid * n - (mid - 1) * mid / 2;
            if (val >= m) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        long long root = lo;
        long long maxVal = lo * n - (lo - 1) * lo / 2;
        long long diff = maxVal - m;
        cout << root << "\n";
        for (long long i = 1; i <= root-1; i++) {
            cout << i << " " << root << "\n";
        }
        for (long long i = root+1; i <= root + diff; i++) {
            cout << i << " " << (root-1) << "\n";
        }
        for (long long i = root+diff+1; i <= n; i++) {
            cout << i << " " << root << "\n";
        }
    }
}