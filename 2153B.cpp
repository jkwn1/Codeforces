// Codeforces Round 1057 (Div. 2) B
// https://codeforces.com/contest/2153/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (((x & y) == (x & z)) && ((x&y) ==  (y & z))) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
