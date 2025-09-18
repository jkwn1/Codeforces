#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; ++t1) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;

        if (n % p == 0) {
            if (q * n / p == m) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "YES\n";
        }
    }
}
