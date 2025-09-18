// Educational Codeforces Round 179 (Rated for Div. 2) B
// https://codeforces.com/contest/2111/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> fibonnacies = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, m; cin >> n >> m;
        int twoSide = fibonnacies[n];
        int oneSide = fibonnacies[n+1];
        if (n == 1) {
            oneSide = 1;
        }
        for (int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            if (a > b) {
                swap(a, b);
            }
            if (b > c) {
                swap(b, c);
            }
            if (a > b) {
                swap(a, b);
            }
            if (a >= twoSide && b >= twoSide && c >= oneSide) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << "\n";
    }
}
