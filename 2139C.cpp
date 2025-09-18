#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int k;
        long long x;
        cin >> k >> x;
        int mult = 0;
        while (x > 0) {
            if (x % 2 == 0) {
                mult++;
                x /= 2;
            }
            else {
                break;
            }
        }
        cout << k - mult << "\n";
        long long y = pow(2, k-mult+1) - x;
        y -= 1;
        y /= 2;
        string s = "";
        for (int i = 0; i < k - mult; i++) {
            if (y % 2 == 0) {
                s += "2 ";
            }
            else {
                s += "1 ";
            }
            y /= 2;
        }
        cout << s << "\n";
    }
}