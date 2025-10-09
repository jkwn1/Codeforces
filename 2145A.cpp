// Educational Codeforces Round 183 (Rated for Div. 2) A
// https://codeforces.com/contest/2145/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        int k = n % 3;
        if (k == 0) cout << 0 << "\n";
        else if (k == 1) cout << 2 << "\n";
        else cout << 1 << "\n";
    }
}
