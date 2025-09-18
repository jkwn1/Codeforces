#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t0 = 0; t0 < t; t0++) {
        int n; cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (b > d) {
                sum += a + b - d;
            }
            else if (a > c) {
                sum += a - c;
            }
        }
        cout << sum << "\n";
    }
}