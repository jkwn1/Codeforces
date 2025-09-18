// Codeforces Round 1033 (Div. 2) and CodeNite 2025 B
// https://codeforces.com/contest/2120/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, s;
        cin >> n >> s;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            if (dx == 1) {
                if (dy == 1) {
                    if (x == y) {
                        count++;
                    }
                }
                else {
                    if (s - x == y) {
                        count++;
                    }
                }
            }
            else {
                if (dy == 1) {
                    if (x == s - y) {
                        count++;
                    }
                }
                else {
                    if (x == y) {
                        count++;
                    }
                }
            }
        }
        cout << count << "\n";
    }
}
