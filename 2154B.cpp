// Codeforces Round 1060 (Div. 2) B
// https://codeforces.com/contest/2154/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        vector<int> a(n+2, 0);
        vector<int> pm(n+2, 0);
        int count = 0;

        for (int i = 1; i < n+1; i++) {
            int a0; cin >> a0;
            a[i] = a0;
            pm[i] = max(pm[i-1], a[i]);
            if (i % 2 == 0) {
                a[i] = pm[i];
            }
        }
        a[0] = 1e9+1;
        a[n+1] = 1e9+1;
        for (int i = 1; i < n+1; i+=2) {
            if (a[i] >= a[i+1] || a[i] >= a[i-1]) {
                count += a[i] - min(a[i+1], a[i-1]) + 1;
            }
        }
        cout << count << endl;
    }
}
