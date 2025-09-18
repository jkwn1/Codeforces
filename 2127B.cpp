#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        int x; cin >> x;
        string s; cin >> s;
        if (x == 1 || x == n) {
            cout << 1 << "\n";
            continue;
        }
        int left = 1;
        int right = 1;
        for (int i = x-2; i >= 0; i--) {
            if (s[i] == '#') {
                left = i+2;
                break;
            }
        }
        for (int i = x; i < n; i++) {
            if (s[i] == '#') {
                right = n-i+1;
                break;
            }
        }
        if (left == right) {
            cout << left << "\n";
        }
        else if (left > right) {
            cout << min(left, n - x+1) << "\n";
        }
        else {
            cout << min(right, x) << "\n";
        }
    }
}
