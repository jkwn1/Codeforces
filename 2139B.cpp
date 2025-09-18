#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        long long sum = 0;
        if (m > n) {
            for (long long i = m; i > m - n; i--) {
                sum += a[m - i] * i;
            }
        }
        else {
            for (int i = m; i >= 1; i--) {
                sum += a[m-i] * i;
            }
        }
        cout << sum << "\n";
    }
}