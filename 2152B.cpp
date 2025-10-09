// Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2) B
// https://codeforces.com/contest/2152/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int t1 = 0; t1 < t; t1++) {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) {
            x1 = n - x1;
            x2 = n - x2;
        }
        if (y1 > y2) {
            y1 = n - y1;
            y2 = n - y2;
        }
        int ans = 0;
        int moves = y1;
        int dist1 = max(0, x2-x1-y1);
        int dist2 = y2-y1;
        if (dist2 != 0) {
            if (dist1 == 0) {
                ans = max(ans, moves + dist2);
            }
            else {
                ans = max(ans, max(moves + dist2, moves + x1 + dist1));
            }
        }
        moves = x1;
        dist1 = x2-x1;
        dist2 = max(0, y2-y1-x1);
        if (dist1 != 0) {
            if (dist2 == 0) {
                ans = max(ans, moves + dist1);
            }
            else {
                ans = max(ans, max(moves + dist1, moves + y1 + dist2));
            }
        }
        cout << ans << "\n";
    }
}
