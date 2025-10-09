// Educational Codeforces Round 183 (Rated for Div. 2) B
// https://codeforces.com/contest/2145/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, k; cin >> n >> k;
        string s;
        cin >> s;
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == '0') {
                c0++;
            }
            else if (s[i] == '1') {
                c2++;
            }
            else {
                c1++;
            }
        }
        string ans = "";
        for (int i = 0; i < c0; i++) {
            ans += "-";
        }
        if (c0 + c1 + c2 == n) {
            for (int i = 0; i < (n - c0); i++) {
                ans += "-";
            }
        }
        else if (c0 + 2 * c1 + c2 <= n) {
            for (int i = 0; i < c1; i++) {
                ans += "?";
            }
            for (int i = 0; i < n-c0-2*c1-c2; i++) {
                ans += "+";
            }
            for (int i = 0; i < c1; i++) {
                ans += "?";
            }
            for (int i = 0; i < c2; i++) {
                ans += "-";
            }
        }
        else {
            for (int i = 0; i < (n - c0 - c2); i++) {
                ans += "?";
            }
            for (int i = 0; i < c2; i++) {
                ans += "-";
            }
        }
        cout << ans << "\n";
    }
}
