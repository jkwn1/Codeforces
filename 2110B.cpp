// Codeforces Round 1026 (Div. 2) B
// https://codeforces.com/contest/2110/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        string s;
        cin >> s;
        int n = s.length();
        int openCount = 1;
        int end = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '(') {
                openCount++;
            }
            else {
                openCount--;
                if (openCount == 0) {
                    end = i;
                    break;
                }
            }
        }
        if (end == n-1) {
            cout << "NO" << "\n";
        }
        else {
            cout << "YES" << "\n";
        }
    }
}
