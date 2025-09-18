#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; ++t1) {
        int n;
        cin >> n;
        int totalWinners = 0;
        int prev = 1;
        bool poss = true;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            totalWinners += x;

            if (prev == 0 && x == 0) {
                poss = false;
            }
            else {
                prev = x;
            }
        }
        if (poss && totalWinners != n) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}