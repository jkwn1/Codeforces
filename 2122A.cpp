// Order Capital Round 1 (Codeforces Round 1038, Div. 1 + Div. 2) A
// https://codeforces.com/contest/2122/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, m;
        cin >> n >> m;
        if (n >= 2 && m >= 2) {
            if (n >= 3 || m >= 3) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "NO\n";
        }
    }
}
