// Codeforces Round 1030 (Div. 2) A
// https://codeforces.com/contest/2118/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, k; cin >> n >> k;
        if (n == k) {
            string ans(n, '1');
            cout << ans << "\n";
        }
        else if (n-1 == k) {
            string ans(n-1, '1');
            ans += "0";
            cout << ans << "\n";
        }
        else if (k >= 2) {
            string part1 = "1";
            string part2(n-k-1, '0');
            string part3(k-1, '1');
            string part4 = "0";
            cout << part1 << part2 << part3 << part4 << "\n";
        }
        else if (k == 1) {
            string ans(n-1, '0');
            cout << "1" + ans << "\n";
        }
        else {
            string ans(n, '0');
            cout << ans << "\n";
        }
    }
}
