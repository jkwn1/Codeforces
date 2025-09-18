// Codeforces Round 1020 (Div. 3) B
// https://codeforces.com/contest/2106/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int t1 = 0 ; t1 < t ; t1++) {
        int n, x;
        cin >> n >> x;

        if (n == x) {
            for (int i = 0; i < n; i++) {
                cout << i << " ";
            }
            cout << "\n";
            continue;
        }

        for (int i = 0; i < x; i++) {
            cout << i << " ";
        }
        for (int i = n-1; i > x; i--) {
            cout << i << " ";
        }
        cout << x << "\n";
    }

}
