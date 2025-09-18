#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        int a, b; cin >> a >> b;
        if (n % 2 == 0) {
            if (b % 2 == 0 && (a % 2 == 0 || b >= a)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
        else {
            if (b % 2 == 1 && (a % 2 == 1 || b >= a)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}